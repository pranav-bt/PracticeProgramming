#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};
class LRUCache : public Cache
{
private:
    int capacityused = 0;
public:
    LRUCache(int capacity) { cp = capacity; };
    void set(int key, int valuee)//set function
    {
        if (!head && capacityused < cp)
        {
            Node* newnode = new Node(key, valuee);
            head = newnode;
            tail = newnode;
            mp.insert(std::pair<int, Node*>(key, newnode));
            capacityused++;
        }
        else
        {
            bool done = false;
            map<int, Node*>::iterator it;
            if (!done && mp[key])
            {
                auto val = mp.find(key);
                mp.erase(val);
                Node* node = new Node(key,valuee);
                mp.insert(std::pair<int, Node*>(key, node));
                done = true;
            }
            if (!done && capacityused < cp)
            {
                Node* newnode = new Node(key, valuee);
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                capacityused++;
                done = true;
                mp.insert(std::pair<int, Node*>(key, newnode));
                mp[key] = newnode;
            }
            else if (!done && capacityused >= cp)
            {
                tail = (tail->prev);
                if(tail->next)
                auto it = mp.find((tail->next)->key);
                mp.erase((tail->next)->key);
                delete (tail->next);
                tail->next = nullptr;
                Node* newnode = new Node(key, valuee);
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                done = true;
                mp.insert(std::pair<int, Node*>(key, newnode));
                mp[key] = newnode;
            }
        }
    }
    int get(int val)
    {
        if (mp[val])
        {
            auto node = mp[val];
            if (head == node)
            {
                return node->value;
            }
            if (node->prev)
            {
                (node->prev)->next = node->next;
            }
            if (node->next)
            {
                (node->next)->prev = node->prev;
            }
            if (tail == node)
            {
                tail = node->prev;
            }
            node->next = head;
            head->prev = node;
            head = node;
            head->prev = nullptr;
            return node->value;
        }
        else
        {
            return -1;
        }
    }
};
int AbstractPolymorphism() 
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}

void StringDup()
{
    char* src = new char[100];
    //src = "Default";
    std::cout << "Insert a string\n";
    std::cin >>(src);
    char* str;
    char* p;
    int len = 0;
    while (src[len])
        len++;
    str = (char*)malloc(len + 1);
    p = str;
    while (*src)
        *p++ = *src++;
    *p = '\0';
    std::cout << str;
}

vector<int> Final = {0};
void moveleft(int index, int number, int length, int d)
{
    int value = number;
    if (index < d)
    {
        int tempindex = length - (d - index);
        Final.insert(Final.begin() + tempindex, value);
    }
    else
    {
        int tempindex = index - d;
        auto it = Final.begin() + tempindex;
        Final.insert(it, value);
    }
}
vector<int> rotateLeft(int d, vector<int> arr) {
    int counter = 0;
    int temp;
    int length = arr.size();
    while (counter < length)
    {
        moveleft(counter, arr[counter], length, d);
        counter++;
    }
    for (auto it : Final)
    {
        cout << it;
    }
    return Final;
}

int maximumQuality(int c, vector<int> packets)
{
    int ans = 0;
    int i = 0;
    i = packets.size()-1;
    sort(packets.begin(), packets.end());
    while (c != 1)
    {
        ans += packets[i];
        i--;
        c--;
    }
    if (i % 2 != 0)
    {
        ans += packets[((i - 1) / 2) + 1];
    }
    else
    {
        ans += (packets[i / 2] + packets[i / 2 + 1])/2;
    }
    return ans;
}

int main()
{
    int a;
    std::cout << "Press 1 for Polymorphism Test \n";
    std::cout << "Press 2 for StrDup Test\n";
    std::cout << "Press 3 for LeftRotationArray\n";
    std::cin >> a;
    switch (a)
    {
    case 1:
        AbstractPolymorphism();
    case 2:
        StringDup();
    case 3:
        //vector<int> asd = { 1,2,3,4,5,6,7,8 };
        ///*cout << "vector input\n";
        //cin <<*/ 
        //rotateLeft(4,asd);
    case 4:
        vector<int> vectt = { 2,4,3,6,7 };
        std::cout << maximumQuality(3, vectt);
    }
}
