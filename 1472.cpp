// 1472. Design Browser History

class BrowserHistory {
public:
    class ListNode{
        public:
            string str;
            ListNode *next, *prev;
            ListNode() {
                str = "", next = prev = nullptr;
            }
            ListNode(string s) {
                str = s, next = prev = nullptr;
            }
    }; 
    ListNode *curr;
    BrowserHistory(string homepage) {
        curr = new ListNode(homepage); 
    }
    
    void visit(string url) {  
        curr->next = new ListNode(url);         // also Clears forward history itself:  // if (curr->next != nullptr)   curr->next = nullptr; 
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) { 
        while (steps-- && curr->prev != nullptr)  
            curr = curr->prev; 
        return curr->str;
    }
    
    string forward(int steps) { 
        while (steps-- && curr->next != nullptr) 
            curr = curr->next; 
        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */