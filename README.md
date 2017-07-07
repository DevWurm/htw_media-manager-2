# Media Manager 2
Media Manager 2 is a simple C++ tool for keeping track of borrowed media.

It stores the title, the creator and the creation year of different types of media 
and a list of contacts, which can borrow those media. It provides an graphical user interface for creating, showing and 
deleting media and contacts and associating them.

The tool stores the information to the file `.htw-media-manager-data.xml` in the users home
directory.

## Dependencies
Media Manager uses [Qt 4.8](http://doc.qt.io/qt-4.8/) application framework.
Therefore Qt 4.8 has to be installed on your system.

## Build
Media Manager uses `qmake` as Build system

To build the programm run
```sh
qmake && make clean && make
```

This generates the executable `htw_media-manager-2`.

## Usage information
### Borrowing media
To borrow a medium to a contact double click into the borrower cell of a medium
and choose the contact from the occurring drop down list.

To take back a medium choose 'none' from the list.

### Deleting contacts
Media as well as contacts can be deleted by selecting them in the table and 
pushing the delete button.

If you delete a contact which has still borrowed a medium it is removed from the contacts
list but is still stored in the medium (because it's still the borrower). It
is finally removed, when you take back the medium.

## License
`htw_media-manager` is offered under MIT License (Read LICENSE).<br>
Copyright 2017 Leo Lindhorst

## Contact
If you have any questions, ideas, etc. feel free to contact me:<br>
Leo Lindhorst<br>
Email: <a href='mailto:devwurm@devwurm.net'>devwurm@devwurm.net</a><br>
Jabber: devwurm@conversations.io<br>
Twitter: @DevWurm<br>
