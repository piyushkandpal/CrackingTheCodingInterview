#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*The method receivedAddRequest, in the User class, notifies User B that User A
 * has requested to add him. User B approves or rejects the request (via UserManager.
 * approveAddRequest or rejectAddRequest), and the UserManager takes care of
 * adding the users to each other's contact lists.
 
 The method sentAddRequest in the User class is called by User-Manager to add an
 AddRequest to User A's list of requests. So the flow is:
 1. User A clicks "add user" on the client, and it gets sent to the server.
 2. User A calls requestAddUser (User B).
 3. This method calls UserManager. addUser.
 4. UserManager calls both User A. sentAddRequest and
 User B.receivedAddRequest.
 */
class UserManager
{
    private:
        static UserManager* instance;
        // map from userId to a user
        map<long int,User> usersById;
        // map from account id to username
        map<string,User> usersByAccountName;
        // map from user id to online user
        map<string,User> onlineUsers;
    public:
        static UserManager* getInstance()
        {
            if (instance == NULL)
                instance = new UserManager;
            return instance;
        }
        void addUser(User& fromUser,string& toAccountName);
        void approveAddRequest(AddRequest& req);
        void rejectAddRequest(AddRequest& req);
        void userSignedOn(string& accountName);
        void userSignedOff(string& accountName);
}
class User
{
    private:
        int id;
        UserStatus status = NULL;
        //map form other participant's userid to the chat
        map<long int,PrivateChat> privateChats; 
        //vector of group chat ids that involves current (this) user .. 
        //no point keepimg a map as these dont map to any specific user .. rather they have an id of own 
        vector<GroupChat> groupChats; 
        // map form other person's userid to add requests
        map<long int,AddRequest> receivedAddRequests;
        // map form other person's userid to add requests
        map<long int,AddRequest> sentAddRequests;
        // map from user Id to add request
        map<long int,User> contacts;
        string accountName;
        string fullName;
    public:
        User(long int& id, string& accountName, string& fullName);
        boolean sendMessageToUser(User& to, string& content);
        boolean sendMessageToGroupChat(int& id, string& content); // this would in turn send message to each user via sendMessageToUser
        void setStatus(UserStatus& status);
        UserStatus getStatus();
        boolean addContact(User& user);//add to map contacts
        void receivedAddRequest(AddRequest& req);
        void sentAddRequest(AddRequest& req);
        void removeAddRequest(AddRequest& req) ;
        void requestAddUser(string accountName) ;
        void addConversation(PrivateChat& conversation) ;
        void addConversation(GroupChat& conversation) ;
        int getId();
        string getAccountName();
        string getFullName();
}
/*
The Conversation class is implemented as an abstract class, since all Conversations
must be either a GroupChat or a PrivateChat, and since these two classes each have
their own functionality.
*/ 

class Conversation 
{
  protected:
     vector<User> participants;
     int id;
     vector<Message> messages;

  public:
     vector<Message> getMessages();
     boolean addMessage(Message& m);
     int getId();
};

class GroupChat:public Conversation 
{
   public:
     void removeParticipant(User& user);
     void addParticipant(User& user);
};


class PrivateChat:public Conversation 
{
    public: 
        PrivateChat(User& userl, User& user2);       
        User getOtherParticipant(User& primary); 
};

class Message 
{
    private: 
        String content;
        Date date;
    public:
         Message(String content, Date date); 
         String getContent();
         Date getDate();
};
/*
AddRequest and UserStatus are simple classes with little functionality. Their main
purpose is to group data that other classes will act upon.
*/
class AddRequest 
{
    private:
        User fromUser;
        User toUser;
        Date date;
        RequestStatus status;
    public:
        AddRequest(User from, User to, Date date); 
        RequestStatus getStatus();
        User getFromUser();
        User getToUser();
        Date getDate();}
};

class UserStatus 
{
    private:
         String message;
        UserStatusType type;
    public: 
         UserStatus(UserStatusType type, String message);
         UserStatusType getStatusType();
         String getMessage();
};
enum UserStatusType {Offline, Away, Idle, Available, Busy};
enum RequestStatus {Unread, Read, Accepted, Rejected};



