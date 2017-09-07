INSTALL INSTRUCTIONS

A. Clone project. E.g., to D:/code/DataElephant

B. Add D:/code/DataElephant to MATLAB path.

C. Mex the file CalcMD5.c located in the root DataElephant folder.
First move into the DataElephant root folder in MATLAB (e.g., D:/code/DataElephant), then enter the following commands in the command window.
On windows:
mex CalcMD5.c
On linux:
mex -O CFLAGS="\$CFLAGS -std=c99" CalcMD5.c

D. Create a new folder for storage of data. For example:
- On windows, create D:/StorageElephants
- On linux, create /home/fdrop/StorageElephants

E. Create a new folder for temporary storage of data. For example:
- On windows, create  D:/TemporaryElephants
- On linux, create /home/fdrop/TemporaryElephants

F. You need to tell DataElephant about these two folders. There are two options:

1. Edit the @DataElephant/config.m file.

    a. Find your hostname, by typing [~, name] = system('hostname'). For example, if your hostname is 'JohnDoeDesktop', this command would return: name = 'JohnDoeDesktop'

    b. Copy+paste the list of options from the 'otherwise' case inside @DataElephant/config.m, and modify the case expression to your hostname. For example: case 'JohnDoeDesktop'

    c. On Windows, change s.win_root to the path to your storage folder. For example: s.win_root = 'D:/StorageElephants';

    d. On Windows, change s.win_temp to the path to your temporary storage folder. For example: s.win_temp = 'D:/TemporaryElephants';

    e. On Linux, change s.unix_root to the path to your storage folder. For example: s.unix_root = '/home/fdrop/StorageElephants';

    f. On Linux, change s.unix_temp to the path to your temporary storage folder. For example: s.win_temp = '/home/fdrop/TemporaryElephants';

2. Set the correct option when creating a DataElephant object.

    a. On Windows, create a DataElephant object with the options 'win_root' and 'win_temp' set to the paths of your storage and temporary storage folders.
        For example: a = DataElephat(@example,'win_root','D:/StorageElephants','win_temp','D:/TemporaryElephants');

    b. On Linux, create a DataElephant object with the options 'unix_root' and 'unix_temp' set to the paths of your storage and temporary storage folders.
        For example: a = DataElephat(@example,'unix_root','D:/StorageElephants','unix_temp','D:/TemporaryElephants');

Note that options set while creating a new DataElephant object always override options set in the config file.

G. Open the file 'demo.m' in one of the folders inside the examples folder.
Make sure that the current 'win_root', 'win_temp', 'unix_root', and 'unix_temp' options are either removed (when you edited the config file) or set to the correct folder (see F.2).