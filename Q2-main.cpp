#include"Q2.cpp"

int main()
{
    Vector_based_stack<int> s;
    
    if(s.empty()) //check if stack's empty
        cout<<"Stack is empty."<<endl;
    else cout<<"Stack is not empty."<<endl;

    s.push(1); //insert an integar value (1) onto the stack
    s.push(5); //insert an integar value (5) onto the stack
    s.push(8); //insert an integar value (8) onto the stack;
    s.pop(); //remove an integar from the stack
    cout<<"Top of the stack: ";
    cout<<s.top()<<endl;//print the top value of the stack
    if(s.empty()) //check if stack's empty
        cout<<"Stack is empty."<<endl;
    else cout<<"Stack is not empty."<<endl;
    double sum = 0;
    int cnt = 0;
    while(s.empty()==false) //stack is not empty
    {
        sum+= s.top(); //add the top value of stack to sum variable
        s.pop(); //removing the top value
        cnt++; //incrementing the count 
    }

    cout<<"Average is "<<sum/cnt<<endl;//print average value of the stack element
    

}
