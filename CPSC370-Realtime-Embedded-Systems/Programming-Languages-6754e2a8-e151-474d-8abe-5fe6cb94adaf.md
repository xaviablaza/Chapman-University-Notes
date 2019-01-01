# Programming Languages

# Features that are related to programming language

- Misuse of the programming language is often a source of performance deterioration and missed deadlines
- You will call a library that you didn't write, and their code generates a library
- C says that there are no rules for a prototype, you can pass in the wrong parameters and cause havoc
- Programming is craft-like and as with any craft, the best practitioners are known for the quality of their tools and their skill with them
    - Standards are important, make sure to follow general rules of thumb
- Real-time systems have been built with a wide range of programming languages

> A fool with a tool is still cool.

- Extreme programming
    - Effective C, C++, Java

# Language taxonomies

- Imperative, functional, logic, other
- Procedural or declarative
- Assignment of variables
- Functional (applicative) languages employ repeated application of some function (e.g. LISP)

In choosing a language...

# Cardelli's metrics

- **Economy of execution.** How fast does a program run?
- **Economy of compilation.** How long does it take to go from sources to executables?
- **Economy of small-scale development.** How hard must an individual programmer work?
- **Economy of large-scale development.** How hard must a team of programmers work?
- **Economy of language features.** How hard is it to learn or use a programming language?

# Schedulability analysis

- Can you predict how long it is going to take to compile this stuff?
- We need to know what data looks like when sending stuff over the network
- Heteregeneity - different processor types
    - Big endian vs little endian
    - XDR - Sun Microsystems. We can take data and represent it in some platform agnostic form, where each side will do its own conversion
- We wanna provide typesafe language mechanisms

# Assembly Language

- MIPS
- Use it only if you have to
- Excellent economy of execution
- Excellent economy of compilation
- Poor economies of small and large-scale development, language features
- Its use in embedded real-time systems is discouraged
    - Lacks features of high level languages
    - Is unstructured and has limited abstraction properties
    - Is usually difficult to learn, tedious, and error prone,
    - Resulting code is non-portable
    - It is rare than even the best programmers can "beat" a good optimizing compiler
    - 8086, 68K processors

    read_reg()
    write_reg()
    read_reg()
    
    quiesce (wait for hardware to work)

Optimization can kill you in this scenario, because the 2nd read would go before the write.

# Parameter passing techniques

- Pass by value vs pass by reference
- Pass by reference, passes a pointer
- You change the value in the function itself
- Indirect memory address call if you pass by reference

# Global Variables

- Never pass a global variable into a function
- Stay away from it as much as possible

# Recursion

- Not recommended for embedded systems because there should be an elegant way to exit out of it
- Some compilers will support it, some won't

# Dynamic Memory Allocation

- Do we wanna do it in embedded systems? Encouraged, but you need to be very careful
- You can suck up all your memory
- Embedded systems won't clean it up if you just exit all of a sudden
- `memscope`
- Valgrind

# Typing

- Typed languages require that each variable and constant be of a specific type declared before use

# Modularity

- Keep it as modular as possible

# Procedural Style

- Small-scale development is economical - type checking can catch many coding errors

# Object-oriented languages

- Software reuse, inheritance, etc.

# Synchronizing objects

- Synchronized objects e.g. Mutex
    - Internal vs external locking
- Encapsulated objects

# Garbage Collection

- We don't know when it's going to happen, so it can be detrimental to real-time performance

# Metrics in Object-Oriented Languages

- Less efficient in execution - every routing is a method
- Economy of compilation is law
- Caches might be missed
- Superior with respect to economy of small-scale development
- Economy of large-scale development is low - languages have poor modularlity properties
- OO languages have low economy of language features

# OO vs Procedural

- C++ handling of exceptions
- Java used in embedded systems

# Requirements engineering process

- Functional
- External interfaces
- Performance
- Logical database
- Design constraints
- Software system attributes
- 

## Functional requirements

- All system inputs
- Exact sequence of operations and responses to normal and abnormal situations for every input possibility
- May use case-by-case description or other general form of description

## Performance requirements

- Static and dynamic requirements placed on the software or on human interaction with the software as a whole
- Might include
    - the number of simultaneous users to be supported
    - the numbers of transactions and tasks the amount of data to be processed within certain time periods for both normal and peak workload conditions

# Software system attribute requirements

- Reliability

A measure of whether a user can depend on the software. For real-time systems, other informal characterizations of reliability might include

- Downtime is below a certain threshold
- The accuracy of the system is within a certain tolerance
- Real-time performance requirements are met consistently

- Availability
- Security
- Maintainability

A software system in which changes are relatively easy to make, has a high level of maintainibility. Two contributing properties - evolvavbility and reparability

Evolvability is a measure of how easily the system can be changed to accomadate new features or modification of existing features

Software is repairable if it allows for the fixing of defects.

- Portability
- Verifiability
- Usability

Often referred to as ease of use, or user friendliness. Usability is difficult to quantify. However, informal feedback can be used, as well as user feedback from surveys and problem reports can be used in most cases.

- Performance

A measure of some required behavior. For example, an imaging system might be required to display a filtered image at a rate of 30 frames per second. A photo reproduction system might be required to digitize, clean, and output color copies at a rate of 1 every two seconds. Can be measured via mathematical or algorithmic complexity, direct timing or simulation.

- Corectness

Closely related to reliability and the terms are often used interchangeably. The main difference is that minor deviation from the requirements is strictly considered a failure and hence means the software is incorrect. However, a system may still be deemed reliable if only minor deviations from the requirements are experienced

- Interoperability

Refers to the ability of the software system to coexist and cooperate with other systems. In imaging systems, the software must be able to communicate with various devices using standard bus structures and protocols. Open systems and standards foster interoperability. Interoperability can be measured in terms of compliance with open system standards.

- Just about any "ility" you can think of
- 

## Finite state machines

- Finite state machine, or State Transition Diagram is a formal mathematical model used in the specification and design of a wide range of systems
- Rely on the fact that many systems can be represented by a fixed number of unique states. The system may change state depending on time or the occurence of specific events - a fact that is reflected in the automaton
- Can be specified in diagrammatic, set theoretic and matrix representations

# Requirements

- There is no one way to do it. Various ways include:
    - Top-down process decomposition or structured analysis
    - Object-oriented approaches
    - Program description languages (PDL) or pseudo-code
    - High-level functional specifications that are not further decomposed
    - Ad hoc techniques, including simply natural language and mathematical description, and are always include in virtually every system specification

- Data flow is what you passed into that function
- Control flow is a procedure call

## Target document

- Data dictionary

## Context Diagram

- Camera is fed an image
- Detector detects a new_product_event
- Visual Inspection System
- Reject mechanism
- Accept it onto the conveyor controller

## Temporal logic

- P-tree networks
- We can apply different time models (sequence diagrams)
- temporal automata

# Semaphores Hands-on

A semaphore (sometimes called a semaphore token) is a kernel object that one or more threads of execution can acquire or release for the purposes of synchronization or mutual exclusion.

A task is blocked when it is waiting for a semaphore to be released.

A mutex semaphore (only the task that acquired it can release it)

A binary semaphore can have a value of either zero or one. When zero, the semaphore is considered unavailable. When the value is one, the binary semaphore is considered available. Binary semaphores are treated as global resources.

## Counting Semaphores

- A counting semaphore uses a count to allow it to be acquired or released multiple times (another task can acquire it when you don't want it to)
- One or more tasks can continue to acquire a token from the counting semaphore until no tokens are left
- Counting semaphores are treated as global resources (see state diagram of a counting semaphore)

## Recursive Locking

- Allows the task that owns the mutex to acquire it multiple times
- Used when a task requiers exclusive access to a shared resource that calls one or more routines that also require access to the same resource
- A recursive mutex allows nested attempts to locked the mutex

## Task Deletion Safety

- Some mutex implementations have build-in *task deletion safety*
- Premature task deletion is avoided by using *task deletion locks* when a task locks and unlocks a mutex
- If a task acquires a semaphore and if the task is deleted with the semaphore is acquired, then kernel doesn't allow task to be deleted until he semaphore is released

## Priority Inversion Avoidance

- *Priority inversion* occurs when a higher priority task is blocked and waiting for a resource being used by a lower priority task, which has itself been preempted by an unrelated medium-priority task.
    - The higher priority task's priority level has effectively been inverted to the lower priority task's level
- Two common protocols used...

## Typical Semaphore Operations

- Creating and deleting semaphores
- Acquiring and releasing semaphores
- Clearing a semaphore's task-waiting list
- Getting semaphore information

## Acquiring and Releasing Semaphores

- Tasks typically make a request to acquire a semaphore in one of the following ways
    - Wait forever
    - Wait with a timeout
    - Do not wait - task makes a request to acquire a semaphore token, but if there is none available then the task does not block

Given a cyclic executive where `func1` is waiting for a semaphore, but it can't because task that acquierd semaphore is deleted.

    while(1){
    func1;
    func2;
    func3;
    func4;
    }

We can't wait because we starve func2, func3, func4. If it's not available then go out of the cyclic executive and don't wait.

## Clearing Semaphore Task - Waiting List

- The flush operation is useful for broadcasting signaling to a group of tasks
- This operation frees all tasks waiting in the semaphore's task waiting list
- *Thread rendezvous,* when multiple tasks' executions need to meet at some point in time to synchronize execution control.

## Typical Semaphore Use

- Wait-and-signal synchronization (waiting on a network packet to arrive)
    - Binary semaphore

    tWaitTask() {
    // Acquire binary semaphore token
    }
    tSignalTask() {
    // Release binary semaphore token
    }

What if you have multiple tasks waiting on a semaphore? Use multiple-task wait-and-signal sycnrhornization. We don't know which task will get the semaphore first.

Why do we need a mutually exclusive condition?

2 tasks; one flashes green, one flashes red

Task control block - holds onto the information of the context switch

# NP-completeness

NP hard cannot be solved in polynomial time.

Given a generic program, will the program always halt?

Can we come up with some type of algorithm that guarantees that the generic algorithm will finish?

NP complete problems tend to be those relating to resource allocation, — this is the situation that occurs in real-time scheduling.

## Amdahl's Law

- A statement regarding the level of parallization that can be achieved by a parallel computer
- Amdahl's Law - for a constant problem size, speedup approaches zero as the number of processor elements grow

$$speedup = \frac{n}{1+(n-1)s}$$

## Gustafson's Law

- The problem size cales with the number of processors
- As we add a bigger problem size then we add more processors
- We won't get to the optimal solution, but the curve is better

## Performance analysis

- Code execution time estimation
- Analysis of polled loops
- Analysis of coroutines
- Analysis of round-robin systems
- Response time analysis for fixed period systems
- Response time analysis — RMA example
- Analysis of sporadic and aperiodic interrupt systems
- Deterministic performance

Analysis of round-robin systems

$$T=(n-1)[\frac{c}{q}]q+c$$

Add context switch time overhead of 1ms to get the time to complete the task set

$$T=[(5-1)*100+5*1][\frac{500}{100}]+500=2525$$

Ceiling of the fraction.

## Response time analysis for fixed period systems

## Analysis of sporadic and aperiodic interrupt systems

We need to keep track of interrupts

- Use a rate-monotonic approach with the non-periodic tasks having a period equal to their worst case expected inter-arrival time
- If this leads to unacceptably high utilization, then use a heuristic analysis approach
- Queuing theory can also be helpful in this regard

DMA affects performance because we don't know when they're gonna arrive.

Network packet will come in and it will be stored on a buffer in the card itself. Packet needs to move up the stack.

To do a worst case performance, assume that every instruction is not fetched from cache but from in memory

In the case of pipelines, always assume that at every possible opportunity the pipeline needs to be flushed

When DMA is present in the system, assume that cycle stealing occurring at every opportunity, inflating instruction fetch times

By making some reasonable assumptions about the real impact of these effects, some rational approximation of performance is possible

# Message Queues

A message queue is a buffer-like object through which tasks and ISRs send and receive messages to communicate and synchronize with data. A message queue is like a pipeline. It temporarily holds messages from a sender until the intended receiver is ready to read them. It's lik a mailbox.

Built-in synchronization because we don't need to worry about things overflowing

- Message queue consists of a number of elements, each of which can hold a single message
- When you read the message, you destroy it
- Total number of elements (empty or not) in the queue is the total length of the queue
- A message queue has two associated task-waiting lists
    - The receiving list — consists of task that wait on the queue when it is empty
    - The sending list — consists of tasks that wait on the queue when it is full

Message Queue States

- When a message queue is first created, the FSM is in the empty state
- When empty, the receiver task blocks
- When full, the sender task blocks
- Message queue's task-waiting list, either a FIFO or priority-based order

## Message Queue Content

- Temperature value from a sensor
- Bitmap to draw on a display
- Text message to print to an LCD
- Keyboard event
- Data packet to send over the network

## Message Copying

- Use a pointer instead of a block of data
- Copying data can be expensive in terms of performance and memory requirements
- Important to keep copying to a minimum in a real-time embedded system
    - Keep messages small
    - Use a pointer instead

## Message Queue Storage

- Different kernels store message queues in different locations in memory
    - System pools - messages of all queues are stored in one large shared area of memory
    - Advantage - save on memory use
    - Disadvantage - message queue with large messages can use most of the pooled memory
- Private buffers - separate memory areas

## Message Queue Operations

- Typical message queue operations include the following:
    - Creating and deleting message queues
    - Sending and receiving messages
    - Obtaining message queue information

## Creating and Deleting Messages

- Message queues are treated as global objects and are not owned by any particular task
- Creating a message queue
    - Length of the message queue
    - Maximum size of the messages
    - Waiting order for tasks when they block on a message queue
- Deleting a message queue automatically unblocks waiting tasks
    - The blocking call in each of these tasks returns with an error
    - Messages that were queued are lost when the queue is deleted

## Sending Messages in FIFO Order

- When sending messages, a kernel typically fills a message queue from head to tail in FIFO order
- Each new message is placed at the end of the queue

## Sending Messages in Priority Order

- Many message-queue implementations allow urgent messages to go straight to the head of the queue
- If all arriving messages are urgent, the queuing order effectively becomes last-in/first-out (LIFO)
- Messages are sent to a message queue in the following ways
    - No Block
    - ...

## Receiving Messages

- Tasks can receive messages with different policies
    - Not blocking
    - Blocking with a timeout
    - Blocking forever
- Messages can be read from the head of a message queue in two different ways:
    - Destructive read, and
    - Non-destructive read.

## Message Queue Information

- Different kernels allow developers to obtain different types of information about a message queue
    - Message queue ID
    - Queuing order

## Message Queue Use (you're gonna be asked this on the test)

- Non-interlocked, one-way data communication

    tSourceTask() {
    // Send Message to message queue
    }
    tSinkTask() {
    // receieve message from message queue
    }

- **Interlocked, one-way data communication**

A sending task might require a handshake that the receiving task has been successful in receiving the message

Interlocked communication — sending task sends a message and waits to see if the message is received

This requirement can be useful for reliable communications or task communication

    tSourceTask(){
    	// send message to message queue
    	// acquire binary semaphore
    } // signal to the receiver that you sent it
    tSinkTask() {
    	// receive message from message queue
    	// give binary semaphore
    } // you want to signal to the sender that you got it

- Interlocked two-way communication

    tClientTask() {
    	// Send a messsage to the requests queue
    	// wait for message from server queue
    }
    tServerTask() {
    	// receive a message from the requests queue
    	// send a message to the client queue
    }

Broadcast Communication

    tBroadcastTask() {
    // Send broadcast message to queue
    }
    tSignalTask() {
    // Receive broadcast message
    }

The tasks are interlocked between each other (they depend on each other).

# Testing

We need some type of formal methods to test things.

- Testing is the process of exercising a program with the specific intent of finding errors prior to delivery to the end user
- A good test case is one that has a high probability of finding an error
- A successful test is one that uncovers an error
- You need to try to find faults or issues within the system

Black-box testing

We don't know what's happening inside but we expect this

White-box testing

We know how the system works

## Testing principles

- All tests should be traceable to requirements
- Tests should be planned long before testing begins
- The Pareto principle applies to software testing
- Testing should begin in the small and progress toward testing in the large
- Test to improve quality not just demonstrate correctness
- Exhausting testing in not possible

## Unit level testing

- Black box
    - Exhaustive testing
    - Boundary value testing
    - Random test generation
    - Worst case testing
- White box
    - Judicious test selection
    - Formal program proving
    - Code inspections

## System-level testing

- Top-down testing
    - Start with high-level system and integrate from the top-down replacing individual components by stubs where appropriate
- Bottom-up testing
    - Integrate individual components in levels until the complete system is created
- In practice, most integration involves a combination of these strategies
- Integration is tricky;
    - Patching
    - The probe effect

## Goals of system integration

- Has the most uncertain schedule and is typically the cause of project cost coverruns
- The stage has been set for failure or success at this phase by the specification, design, implementation, and testing practices used throughout the software project life cycle
- Might be difficult to fix problems because it's costly
- Most modern programming practices were devised to ensure arrival at this stage with the fewest errors in the source code

## System unification

- Fitting the pieces of the system together from its individual components is tricky
- Parameter mismatching, variable name mistyping, and calling sequence errors are some of the problems possibly encounterd during system integration
- System unification consists of linking together the tested software modules drawn in an orderly fashion from the source code library to build a load module
- During the linking process, errors are likely to occur that relate to unresolved external symbols, memory assignment violations, page link errors, etc.
- Rebuilding and reloading repaired system can be very tricky and time consuming because of embedded nature

## System verification

- Final system testing of embedded systems often takes days or weeks
- During system validation a careful test log must be kept indicating the test case number, results, and disposition
- If a system test fails all affected tests be rerun after repair
- Even though the module-level test cases and previous system-level test cases have been passed, they may need to be rerun to ensure that no side effects have been introduced during error repair

## Systems integration tools

- Multimeter
- Oscilloscope
- Logic analyzer
- In-circuit emulator
- Software simulator
- Hardware prototypes
- 

## Integration strategy

Add code units in small patches for the big system

## The probe effect

- You can change the experiment by looking at it
- Uncertainty arises because the more closely a system is examined, the more likely the examination process will affect the system
- This is especially true for embedded systems
- Should be taken as a warning that testing methods often affect the systems that they test
- Non-intrusive testing should be considered, like using a logic analyzer

## Voting Schemes / Kalman Filters

- Combine input from two or more process blocks (hardware or software) and combine in some manner
- Voting schemes use majority rule or average of block outputs to obtain final values
- Kalman filters use more sophisticated schemes to reject outliers and other anomalies

## Checkpoints / Test Probes

- Intermediate results are dumped at fixed lcoations
- Can be used during verification or regular operation
- If used during testing only then called a test probe
- Warning: test probes can introduce subtle timing errors

## CPU Testing

- Perform carefully constructed set of tests
- Must be performed with interrupts disabled
- Too slow to perform in foreground
- Catch-22? What should you conclude if CPU determines it has failed?

## Memory Testing - ROM

- Simple checksum
- Polynomial CRC
- Use a checksum to see if the data is correct
- Less sensitive to error cancellation
- Treats memory as a long binary polynomial
- Append O bit for every term in generator polynomial
- Divide polynomial by generator polynomial
- X^16 + X^12 + X^5 + 1 (CCITT)
- X^16 + X^15 + X^2 + 1 (CRC-16)
- Remainder is CRC
- In the end it results in a CRC

## Memory Testing - RAM

- Exhaustive testing
- Walking 1's, walking 0's (parity bit)
    - If there are 3 ones, then you'd expect parity bit to be 0 (even)
- Hamming code-error correction and detection
- RAM scrubbing