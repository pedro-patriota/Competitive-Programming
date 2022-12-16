#include <bits\stdc++.h>


using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    // Discover the data structure
    int num_input, val, query;
    string str_num_input, str_input, str_query, str_val;

    stack<int> test_stack;
    queue<int> test_queue;
    priority_queue<int> test_priority_queue;
    
    bool is_stack, is_queue, is_priority_queue;
    int size;
    while (cin >> num_input)
    {
        is_stack = is_queue = is_priority_queue = true;
        size = 0;
        for (int i = 0; i < num_input; i++)
        {   
            
            cin >> query;
            cin >> val;
            
            if (query == 1)
            {   
                size ++;
                if (is_stack == true)
                {
                    test_stack.push(val);
                }
                if (is_queue == true)
                {
                    test_queue.push(val);
                }
                if (is_priority_queue == true)
                {
                    test_priority_queue.push(val);
                }
            }
            else
            {   
                if (size == 0){
                    is_stack = false;
                    is_queue = false;
                    is_priority_queue = false;
                }else{
                    size --;
                    if (is_stack == true)
                    {
                        if (test_stack.top() != val)
                        {
                            is_stack = false;
                        }
                        else
                        {
                            test_stack.pop();
                        }
                    }
                    if (is_queue == true)
                    {
                        if (test_queue.front() != val)
                        {
                            is_queue = false;
                        }
                        else
                        {
                            test_queue.pop();
                        }

                    }
                    if (is_priority_queue == true)
                    {
                        if (test_priority_queue.top() != val)
                        {
                            is_priority_queue = false;
                        }
                        else
                        {
                            test_priority_queue.pop();
                        }
                    }
                }
            }
        }
        cin.ignore();
        
        test_priority_queue = priority_queue<int> ();
        test_queue = queue<int> ();
        test_stack= stack<int>();
        if (!is_stack && !is_queue && !is_priority_queue)
        {
            cout << "impossible\n";
        }
        else
        {
            if (is_stack + is_queue + is_priority_queue > 1)
            {
                cout << "not sure\n";
            }
            else
            {
                if (is_stack)
                {
                    cout << "stack\n";
                }
                else if (is_queue)
                {
                    cout << "queue\n";
                }
                else if (is_priority_queue)
                {
                    cout << "priority queue\n";
                }
            }
        }
    }
}