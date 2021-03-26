# CSI 387 Detailed Design Document <p style = "font-size:13px; line-height:1.4">Written by: Adrian Leung, Jason Kalili, and Carter Pon</p>

## 2.1 – Detailed list of Linux modules that will be modified/affected
We will primarly be modifing the existing 'disk free', or df command in the linux terminal. The df command currently gives a breakdown of system files and how much space they are taking up on the hard disk. We wish to emblish this command by displaying a breakown into categories like 'pictures', 'applications', 'videos', and other classifications. The modality in which we would display this information would be through 'progress bars' similar to those seen when installing a module through the terminal. 

Module   | Description
---------|------------
[/df](https://en.wikipedia.org/wiki/Df_(Unix))      | (abbreviation for disk free) is a standard Unix command used to display the amount of available disk space for file systems on which the invoking user has appropriate read access.
-a       | It is not clear yet if the existing -a argument will be modified but it will definitely be used in our implementation 

## <br>2.2 – Detailed list of any new modules that you will produce [or 'Not Applicable' if there are none]

It seems that the best way to achieve our objective is to modify the current existing /df module rather than implement a new one at this current point in time. If circumstances change we will adapt our implementation to achieve our objective.

## <br>2.3 – Class diagram showing affected modules [and any new modules] and how they related to one another 
![Class Diagram](https://raw.githubusercontent.com/AdrianLearn/CMSI387-AdrianCarterJason/6874e18b105c6433c1f36e6c151d906849fba38d/Projects/02-DetailedDesign/2.3.png?token=AJM7Q5QCMRPT7JWKET5JWKDAM5PQO)

Argument | Description
---------|------------
-a       | It is not clear yet if the existing -a argument will be modified but it will definitely be used in our implementation 
-B       | Prints filesystems on user specified blocksize
-i       | Lists inode information instead of block usage
-k       | Like -B but displays in kilobytes
-t       | Prints filesystem type
-x       | Prints but excludes by user specified type
-s       | our addition to the df argumetn list

## <br>2.4 – List or table of explanations of all command line options that will be implemented

Module -option   | Description
---------|------------
df -s    | Using this command will display the breakdown of the user's files into categories. -s is short for "storage" in our case.
