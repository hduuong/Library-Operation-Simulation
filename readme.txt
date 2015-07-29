Duong Chau
lab4
CSS 343

1/
display works fine. format looks acceptable. Data is read correctly and object got built successfully
Actions/Commands are fully executed and it works correctly.

NO LEAKS : not anymore :)

2/
patronHash: is used to store the patrons in the correct index base on a patron's unique ID

shelfHash: is used to store books under a container of BSTree. books get inserted to the correct
tree by the type of the book it is.

Factory: is used to return the correct type of book that the infile demands.

actionFactory: us used to return the correct type of action the infile demands.

3/
BuildShelf reads the book data and build the self.

4/
BuildActions reads the command data - file passed down by BuildLibrarian
RunLibrarian in main calls the DoitAll in Librarian to execute all actions from the actionQueue.

5/
Did all I could to reduce it.

6/
Being able to understand the roll of the FACTORY - I feel amazed when I can erase a lot of if-else 
my codes look a lot nicer with the existence of FACTORY.