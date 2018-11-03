# Cybersecurity - Networks

# What is a network?

A network is a way to get stuff between two or more things. A **computer network** is a group of **computers** connected together for the purpose of exchanging resources.

## Three Types of Networks

WAN, LAN and P2P

Wide Area Networks exist over large areas.

Data travels through telephone, cable limes, fiber optic lines.

Sometimes requires a modem.

The world's largest Wide Area Network is the Internet.

## Peer to Peer Network

- Usually very small networks
- Each workstation has equivalent capabilities
- No switch or hub required
- Do not work well under heavy data loads

# Network Interfaces

Network interface: device connecting a computer to a network

- Ethernet card
- WiFi adapter
- A computer may have multiple network interfaces
- Packets transmitted between network interfaces
- Most local area networks broadcast frames
- In regular mode, each network interface gets the frames intended for it
- Traffic sniffing can be accomplished by configure the network interface to read all frames

# MAC Addresses

- Most network interfaces come with a predefined MAC address
- A MAC address is a 48-bit number usually represented in hex
- The first three octets of any MAC address are IEEE-assigned Organizationally Unique Identifiers
- The next three can be assigned by organizations as they please, with uniqueness being the only constraint
- Orgnanizations can utilize MAC addresses to identify computers on their network
- MAC address can be reconfigured by network interface driver software

# IP Addressing

- IP addresses consist of 4 octets such as 171.64.20.23
- Each octet consists of numbers between 0 and 255
- It works like the phone system
- Chapman's Network ranges has a few different IP ranges
- 255.255.255.255

# Switch

- A switch is a common network devices
    - Operates at the link layer
    - Has multiple ports each connected to a computer

- Operation of a switch
    - Learn the MAC address of each computer connected to it
    - Forward frames only to the destination computer

    # Combining Switches

    - Switches can be arranged into a tree
    - Each port learns the MAC addresses of the machines in the segment connected to it
    - Fragments to unknown MAC addresses are broadcast
    - Frames to MAC addresses in the same segment as the sender are destroyed

    # Server

    - Users are connected to certain servers which will fulfill the required request
    - Print Servers
    - File Servers
    - Web Servers

    # Routers

    ## Standard Router and Wireless Routers

    - Wether a router is traditional or wireless, its purposes remain the same
    - Routers are specialized computers that send your messages and those of every other internet user speeding to their destinations along thousands of pathways
    - Routers are crucial devices that let messages flow between networks rather than within networks
    - **Go from one network to another network**

    # IP Routing

    - A router bridges two or more networks
        - Operates at the network layer
        - Maintains tables to forward packets to the appropriate network
        - Forwarding decisions based solely on the destination address
    - Routing table
        - Maps range of addressing to LANs or other gateway routers

    # Firewalls

    - A firewall is like a castle with a drawbridge
        - This can be good or bad
    - Only one point of access into the network
    - Can be hardware or software
        - Some routers come with firewall functionality
        - ipfw, ipchains, pf on Unix systems, Windows XP and Mac OS 10 have built in firewalls
    - It controls what goes in and out of the network
    - DMZ - area behind a less restricted firewall that gives you access to the basics
    - Used to filter packets on a combination of features

    # Ports

    - 16 bit numbers identifying where data is directed
    - Computers use port numbers to determine to which process or application message should be delivered
    - Ports 0 through 1023 are reserved for use by known protocols
    - Ports 1024 through 49151 are known as user ports, and should be used by most user programs for listening to connection and the like
    - Port 49142 through 65535 are private used for dynamic allocation by socket libraries

    # Network Utilities

    - Ping - is a simple internet utility that sends a "ping" packet to any computer on the internet/network. The recipient responds with a "ping" reply
        - Allows you to verify if the other computer is functioning and if the network path between you and it, works
        - **Milliseconds** - a fraction of a second used for the packet to go and come back (roundtrip).
        - **DNS Lookup (nslookup) -** converts a domain name to an ip address
        - **Traceroute -** is a utility that attempts to identify all the routers in between you and some other computer on the internet/network
            - Some routers are visible to traceroute and others are not, so it does not provide completely reliable output

# Research/Recon

- Identify the scope of what you want to do

## Ethical Hacking

- Primary goal:
    - To identify the weaknesses of the infrastructure of an organization before an unethical hacker does
- It is legal given testers have taken permission from the relevant stakeholders of the assets on which testing is performed
- It is a subset of an Organization's security program
- It does not just protect the information but helps organizations to succeed

# Reconnaisance

- Focused on collecting as much information as possible about the organization you want to compromise
- Motive is to identify the entry and exit points
- Basic Methods:
- Passive
    - WhoIS, NSLookup, etc.
    - Google Dork
    - DNS Info gathering
    - Social Engineering
- Active
    - Ping
    - Traceroute
- Nmap
- Passive Methods
    - To gain information about targeted organization's cyber infrastructure without actively engaging with th esystems
- Google Dork
    - WHOIS
        - This service is available to anyone with access to the internet
        - Allows users to query various databases and identify the registrant of a domain name and other information
        - Provides information involving: IP address, name servers, admin contact, etc.
        - Link: http://whois.domaintools.com
    - It uses Google search engine to find security holes on the web applications over the internet
    - To locate specific strings of text within search results

## DNS Information Gathering

- dnsenum: tool in the backtrack kali os. it starts querying dns servers and gather information
- host address
- name servers
- mx records
- gathering soa records
- dnsrecon: to gather network infrastructure information
    - dig [example.com](http://example.com) MX @ns0.example.com

# Network Utilities

these are midterm questions

- Active methods (interact directly with a system of interest)
- Ping - determines the reachability of a system
- Traceroute
    - Gathers information about network infrastructure and IP ranges of a given host
    - Displays the overall path hop by hop from source to the destination
- Nmap
    - Network mapping/scanning tool

# Scanning Types

- After completing a successful round of research, we need to create a profile of the target organization
    - Discovering vital network information
    - IP addresses
        - Accessible via Internet, LAN, etc.
    - Ports
    - OS
    - network architecture, services running, etc.
- Types of scanning:
    - Network
    - Port
    - Vulnerabilities
- Network Scanning
    - Discover active host on the network
    - Select a range of IP addresses and initiate a scan over the network
    - Once the scan is complete, the tool provides
        - Network device info
- Tools:
    - Advance IP scanner
    - Network Mapper
    - Nessus

# Nmap

- Used to discover hosts and services on a computer network
- Builds a map of the network by sending specially crafted packets to the target host and then analyzes the responses
- Basic Commands:
    - nmap ipaddress
    - nmap -6 ipaddress
    - nmap -sP ipaddress
    - nmap -PN ipadress
    - nmap -open ipaddress
    - nmap -p T:80 ipaddress
    - nmap -o ipaddress

# Midterm Review

- Hops in between routers, how can these tools be used by someone who is intending to carry out a malicious attack
- How do you gather information?
- What is pen-testing and what are some tools?
- What do you do before carrying out a malicious attack? Recon — can take weeks or months to accomplish
- Remain anonymous
- Delete history, clear logs, etc
- Buffer overflow and how does it affect software? Be ready to find issues and how to fix them. What tools can you use to detect these kinds of issues? Static vs dynamic code analysis
- Why should we have trained professionals?
- Know some nmap commands and a couple of the flags, it's easy

Convert:

    192.168.1.104
    255.255.255.0/24
    
    Convert it to binary, then the network address will be:
    192.168.1.0 - network address
    192.168.1.255
    
    
    /24 subnet is 0-255

The reason why is because we need to find the network address.