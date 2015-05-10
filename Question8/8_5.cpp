#include<iostream>
#include<map>
using namespace std;

class OnlineReaderSystem
{
    private:
        Library *lib;
        UserManager *umgr;
        Display *disp;
        Book activeBook;
        User activeUser;
        
    public:
        OnlineReaderSystem()
        {
            umgr = new UserManager();
            lib = new Library();
            disp = new Display();
            activeBook = NULL;
            activeUser = NULL;
        }
        
        Library *getLibrary() const
        {
            return lib;
        }

        UserManager *getUserMgr() const
        {
            return umgr;
        }

        Display* getDisplay() const
        {
            return disp;
        }
        
        Book getActiveBook() const
        {
            return activeBook;
        }
        
        User getActiveUser() const
        {
            return activeUser;
        }
        
        void setActiveBook(Book b)
        {
            activeBook = b;
            disp.displayBook(b);
        }

        User getActiveUser() const
        {
            return activeUser;
        }

        void setActiveUser(user)
        {
            activeUser = user;
        }
};

class Library
{
    map<int,Book> books;
    public:
    Book addBook(int id,string details)
    {
        if(books.find(id)!=books.end())
        {
            return NULL;
        }
        else
        {
            Book *book = new Book(id,details);
            books[id] = *book;
            // -------------or we cud have done below -------
            // pair<map<int,Book>::iterator, bool> ret;
            // book = Book(id,details);  
            // ret = books.insert(std::pair<int,Book>(id,book));
            // if (ret.second==false) 
            // {
            //     std::cout << "book with book Id id already existed";
            //     std::cout << " with a value of " << ret.first->second << '\n';
            // }
            //
            return book;
        }
    }
    bool remove(Book b)
    {
        // book has its own id
        return remove(b.getId());
    }
    bool remove(int id)
    {
        if(books.find(id)==books.end())
        {
            return false;
        }
        books.erase(id);
        return true;
    }

    Book find(int id)
    {
        map<int,Book>::iterator bookIter = books.find(id);
        if (bookIter != books.end())
            return bookIter->second;
        else
            return NULL;
    }

};

class UserManager
{
        map<int,User> users;
    public:
        User addUser(int id,string details,int accountType)
        {
            map<int,User>iterator iter;
            iter = users.find(id);
            if (iter != users.end())
            {
               return NULL; 
            }
            else
            {
                User user = new User(id,details,accountType);
                users.insert(make_pair(id,user));
                return user;
            }
        }
        
        bool remove(User u)
        {
            return remove(u.getId());
        }
        
        bool remove(int id)
        {
            map<int,User>iterator iter;
            iter = users.find(id);
            if (iter == users.end())
            {
                   return false;
            }
            users.erase(id);
            return true;
        }

        User find(int id)
        {
            map<int,User>iterator iter;
            iter = users.find(id);
            if (iter != users.end())
            {
                   return NULL;
            }
            return iter->second;
        }
};

class Display
{
    Book activeBook;
    User activeUser;
    int pagenumber = 0;
  public:
    void displayUser(User user)
    {
        activeUser = user;
        refreshUserName();
    }
    void DisplayBook(Book book)
    {
        pageNumber = 0;
        activeBook = book;
        refreshTitle();
        refreshDetails();
        refreshPage();
    }
    void TurnPageForward()
    {
        pageNumber++;
        refreshPage();
    }
    void TurnPageBackward()
    {
        pageNumber--;
        refreshPage();
    }
    void refreshUserName() { ...};
    void refreshTitle() { ...};
    void refreshDetails() { ...};
    void refreshPage() { ...};
};

class Book
{
    int bookId;
    string details;
    public:
    Book(int id,string details)
    {
        bookId = id;
        this->details = details;
    }
    int getID()
    {
        return bookId;
    }
    void setId(int id)
    {
        bookId = id;
    }
    string getDetails()
    {
        return details;
    }
    void setDetails()
    {
        details = d;
    }
};

class User
{
    int userId;
    string details;
    int accountType;
  public:
    void renewMembership(){}
    User(int id,string details,int accountType)
    {
        userId = id;
        this->details = details;
        this->accountType = accountType;
    }

    int getId()
    {
        return userId;
    }
    void setId(int id)
    {
        userId = id;
    }
    string getDetails()
    {
        returns details;
    }
    void setDetails(string details)
    {
        this->details = details;
    }
    int getAccountType()
    {
        return accountType;
    }
    void setAccountType(int accountType)
    {
        this->accountType = accountType;
    }
 };

int main()
{
    //Initialize OnlineReaderSystem
    OnlineReader = OnlineReaderSystem();
    // Create a library
    // Create a  user
    // Create a book
    // add user to User Manager
    // add Book to Library
    // find a book
    //
    //
}
