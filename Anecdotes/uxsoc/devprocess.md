# UX Society at Chapman University
I’m an incoming junior at Chapman University in Southern California. I’m a software engineering major. Everyday when class ends, I usually head over to the cafeteria and eat, then bike home. I decided to live a little far from campus than most people without a car would like, but I did so to motivate myself to exercise at least 20 minutes.

Most students head to the beach, or go to Disneyland. Some people also take trips up to Big Bear, or hike at the numerous trails that are a drive away from campus. Some regularly eat out and schedule fun things with their friends like LazerTag.

The typical Chapman student is quite chill and casual.

You know what’s not chill? Running a chapter of the User Experience Society here at Chapman, and having really high expectations both for myself and for other people. Chapman’s culture is quite chill compared to the culture of the Ateneans in the Philippines, where UX Society was founded. I’ll be going over some of the things we have done as a team growing a student organization like UX Society in a culture I really haven’t come to terms with yet.

*This chill culture really bugs me, and hopefully my perspective on this will change with time. It begins with investing in people and building lasting relationships within the organization. These relationships will eventually build up, solving the problem of knowledge transfer and longevity in the long-run.*

## Recruiting Members
Let’s start off with what a very simple formula that we use to spark people’s interest in the organization:

1. Ask a potential prospect about themselves and what they do.
2. Introduce the organization, what it does, and how the organization is in line with what their goals are.
3. Edify the professionals or mentors that you know who are helping the organization.
4. Follow up with them within 24 to 48 hours after your initial contact (this is what I call the 24/48 rule).
5. Set up another meeting with them and give them options (e.g. “are you free Monday or Wednesday?”).
6. Invite them to your meeting and show them the wonderful world of UX.

I realized that what makes people not attend club meetings regularly is that people consider their time very important. It’s hard to get people to do one more extracurricular task outside the tasks outside of class that they already have to do. But like any good growth hacker, there will always be a specific way to persuade someone, and entice someone that being a part of your organization is necessary for their success.

## Meeting Activities
We currently have biweekly meetings where we do a lot of interactive activities like design studios. We also have a Slack channel that we use to communicate with other members; however most of the time our executive board has to reach out to these members individually either through text or email. We also invite other student organizations and have them go through similar activities that our members are being trained to lead. Once we focus on growth after developing a small but effective team, we are looking to alternate our meeting times every week between Wednesdays and Fridays.

So far, we have taken a really intense approach to teaching UX. A lot of people have fallen off our first few meetings but our executive board finds it easier working with a small group of really talented and driven people. We look to train freshman in design, development, and business.

We are also not an events-heavy chapter unlike most student organizations in the Philippines. Pushing for a lot of events hasn’t worked for us. Instead, we pursue a lot of small projects in small teams.

## Our Design & Development Process
What we are really proud of though, is our system in making deliverables after a design spec has been made. Our current process works like so:

1. We gather information from our stakeholders by involving them and our members to go through a design studio.
2. After getting their sketches of what the website would look like, the sketches are consolidated into a single low-fidelity prototype with a moodboard document.
3. The moodboard and the low-fidelity prototype are used to make a high-fidelity prototype.
4. The high-fidelity prototype is sent to the stakeholders for approval.
5. We make any necessary changes, then once the high-fidelity prototype is approved the engineering process begins.
6. We write code (not from scratch) that is in-line with the high-fidelity design specification that’s made on Adobe XD.
7. The website is tested, deployed, and sent to the client.
8. We have a launch party with the client because we’re pretty chill people.

## What does being an international organization even mean?
For the User Experience Society to really prosper as an international organization it is very important to keep in mind the new leaders this organization will bring in. Not every chapter will operate the same way and that is to be expected. Despite this potential caveat, there should be some way to improve the experience of new chapter leaders, and it begins with proper documentation of how the organization operates, inside and out.

## Engineering Websites at Chapman
Brain cycles of humans are expensive and should be used for important things. At our chapter in Chapman University, our executive board has diverted most of our focus into the last mile of the consultancy process, which is the development of the product and its deployment.

I’m going to be talking about simple, statically generated websites. From a development standpoint, anything that can speed up the process of making these deliverables should be used. By reusing requirements, we could be able to re-architect components we have already engineered in the past to achieve other design missions. So how do we do it?

We use Hugo. Our development process is capable of organizing a lot of front-end components we have custom-engineered from previous design specifications into a general-purpose theme. This theme is essentially a catalog of components we can enable and disable at our will to organize sections of a website and specify its contents within one small file.

Just as a proof of concept, we ported [Alexis’ portfolio website](http://alexiscollado.com) into a [Hugo theme](https://github.com/xaviablaza/hugo-lodi-theme), and was able to deploy in a matter of minutes to [GitHub pages](xaviablaza.github.io/hugo-lodi-theme-demo). To spin off a new page (or in this theme, a new case study), there’s no need for complex page wiring. All you need to type is:

`hugo new post.md`

and you’re good to go. You can begin writing your content in markdown.

# The Dream
Perhaps there will come a point in the next few years where we could see international internship opportunities being offered by chapters around the world. For this to even happen, there needs to be international, cross-border collaboration, and it should begin as early as now.
