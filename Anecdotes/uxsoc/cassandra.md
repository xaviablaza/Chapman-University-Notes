# Storing messages on Cassandra

https://blog.discordapp.com/how-discord-stores-billions-of-messages-7fa6ec7ee4c7

The best way to describe Cassandra to a newcomer is that it is a KKV store. The two Ks comprise the primary key. The first K is the partition key and is used to determine which node the data lives on and where it is found on disk. The partition contains multiple rows within it and a row within a partition is identified by the second K, which is the clustering key. The clustering key acts as both a primary key within the partition and how the rows are sorted. You can think of a partition as an ordered dictionary. These properties combined allow for very powerful data modeling.

Every ID should be a Snowflake, where the primary key could be a `(channel_id, message_id)`, where the `message_id` is a Snowflake. So when loading a channel you could tell Cassandra exactly where to range scan for messages.

```
CREATE TABLE messages (
  channel_id bigint,
  message_id bigint,
  author_id bigint,
  content text,
  PRIMARY KEY (channel_id, message_id)
) WITH CLUSTERING ORDER BY (message_id DESC);
```

## Bucketing messages

Bucket the messages by time. Store 10 days of messages within a bucket. Buckets would be derivable from the `message_id` or a timestamp.

```
CREATE TABLE messages (
  channel_id bigint,
  message_id bigint,
  author_id bigint,
  content text,
  PRIMARY KEY ((channel_id, bucket), message_id)
) WITH CLUSTERING ORDER BY (message_id DESC);
```

Only write non-null values to Cassandra.

We solved this by doing the following:
We lowered the lifespan of tombstones from 10 days down to 2 days because we run Cassandra repairs (an anti-entropy process) every night on our message cluster.

We changed our query code to track empty buckets and avoid them in the future for a channel. This meant that if a user caused this query again then at worst Cassandra would be scanning only in the most recent bucket.
