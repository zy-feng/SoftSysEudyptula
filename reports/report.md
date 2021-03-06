# SoftSysEudyptula
## Learning about how operating systems work through Eudyptula challenges

## Olin College of Engineering Software Systems Spring 2018
## Zhengyang Feng and Sungwoo Park

### Project objective
The goal of this project is to complete as many Eudyptula challenges as we can during the timeframe given for this project. Eudyptula is a series of programming exercises for the linux kernel. It gradually gets more complex and difficult, starting from simple “hello world” program to getting a patch accepted by the linux community for the kernel codebase.

We believe that the reasonable lower bound for the project given approximately 1 month time frame is to complete first 10 tasks. However, it should be noted that one of the team members has already completely first few tasks before the official start of the project. Our plan is to independently work on the tasks but work together when it makes sense (cooperate when stuck with a problem, discuss the different implementation strategy, etc).

### Learning goals

By working on this project, we hope to achieve following learning goals:

- Gain more in-depth understanding of how operating systems work in programming level
- Familiarize ourselves with Linux kernel code
- Get more experience in writing professional-level code in terms of code quality and style (A component of each challenge is code quality and style)
- Gain experience in learning and researching about very complex and difficult topic that we do not know very well as of now.

### Resources
- The challenge problems can be found in the link here <https://github.com/agelastic/eudyptula>.

- The official kernel module programming guide can be found here <https://www.tldp.org/LDP/lkmpg/2.6/lkmpg.pdf>. The document touches on

  - How to write and run kernel modules
  - How to format the modules professionally
  - How to link the modules to system calls, memory and processes
  - How to manage multiple modules
  
- The book here <https://bootlin.com/doc/books/ldd3.pdf> talks deep about Linux device and drivers.

- For some tasks, we have included resources that are specific to the task in a corresponding directory.

### Outcome

We were able to complete good number of tasks during this project time. The demonstration of results and outcomes for each task can be found in the `readme.md` of corresponding task directory.

### Reflection

The two team members on the team had started this project from a different starting point. Therefore, we thought that the separate reflection would be more useful to capture our individual experience with this project.

Sungwoo Park: I have started this project from scratch, beginning with "hello world" program of kernel development. I barely had any prior knowledge on the topics of kernels and operating systems, so the initial learning curve for getting started was very steep. Even simple task of installing and building a kernel took me hours. However, I feel like I got the hang of it now. I think I am now more familiar with the work flow of the kernel programming and more confident with being able to debug a problem that I have with my kernel code. It is unfortunate that the large amount of project time for me was spent on learning the basics and not as much as I wanted on working on the tasks. I am not sure if there was anything that I could've done differently, as this problem mainly stems from my lack of prior knowledge and the nature of this area of programming that has steep learning curve.

In terms of meeting the stated learning goals, I think I have met most of them, not to the extent that I anticipated. I was able to learn how to write and run kernel modules and learn more about operating systems. However, because I was not able to reach later tasks, there are some stuff that I did not get to do, like experience of submitting a patch. However, I am satisfied that this project has given me good introduction to this topic, and I feel confident that I would be much more efficient in working on and learning about this topic in the future.

Zhengyang Feng: I was interested in Linux kernel development before this course, and had completed 7 tasks before the project began. I was stuck at the tasks that follow, even having hard time understanding the concepts of `debugfs`, `sysfs`, etc. In this project, I learn a lot based on my previous knowledge and current learning process. I read a lot from the book [Linux device drivers](https://bootlin.com/doc/books/ldd3.pdf), which talks a lot about interfaces between user mod and kernel mod. When trying to complete the tasks, I manage to navigate the Linux source, learning more about the usage of some part of the codes; I know more about development of device drivers, development USB modules and virtual drivers. I also used mutex in the course content for the project during coding, to solve a real reader-writer problem. Kernel modules are very difficult to debug, which takes most of my time and pose a lot of challenge, but I succeed in surviving after weeks of work. I consider myself have completed the learning goals. Throughout practice in the tasks, I have a great time researching the related topics and doing implementations, while getting myself familiar with Linux system interfaces and coding. 


## Common Commands

|Commands|Usage|
|---|---|
|`uname -a`|Linux system info|
|`uname -r`|Kernel version number|
|`lscpu`|CPU architecture info|
|`lsusb -v`|List USB device|
|`dmesg -wH`|Monitor kernel buffer| 
