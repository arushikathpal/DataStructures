class Stack{
    final int max=1000;
    int top;
    
    int a[]=new int[max];
    Stack()
    {
        top=-1;
    }

     void push(int ele)
    {
        if (top>=max)
        {
            System.out.println("Overflow \n");
        }
        else
        {
            a[++top]=ele;
        }
    }
    
      int pop()
    {
        int x=0;
        if(top<=-1)
        {
            System.out.println("Underflow \n");
            
        }
        else{
        
         x=a[top--];
            
        }
        return x;
    }
    
    int peek()
    {
        return a[top];
    }
}

class Test{
 
    static int precedence(char symbol)
    {
        switch(symbol)
        {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                    return 2;
            case '^': 
                    return 3;
        }
        
        return -1;
        
    }
  /*
    static String infixtopostfix(String exp)
    {
        String result= new String("");
        
        Stack s=new Stack();
        for(int i=0;i<exp.length();i++)
        {
            char c= exp.charAt(i);
            if(c>='a' && c<='z'|| c>='A' && c<='Z')
            {
                result+=c;
            }
            else if(c=='(')
            {
                s.push(c);
            }
            else if (c==')')
            {
                while(s.peek()!='(' && s.top!=-1)
                {
                    result+= s.pop();
                }
                
                if(s.peek()=='(')
                {
                    s.pop();
                }
                else{
                    System.out.println("Invalid expression");
                }
                
            }
            
            else //operator
            {
                if(s.top==-1)
                {
                    s.push(c);
                }
                
                else{
                    if(precedence(c)>precedence(s.peek()))
                    {
                        s.push(c);
                    }
                    else{
                        while(s.top!=-1 && precedence(c)<=precedence(s.peek()) )
                        {
                        result+=s.pop();
                        }
                        s.push(c);
                    }
                }
                
            }

        }

        while(s.top!=-1)
        {
            result+=s.pop();
        }
        
        return result;
    }
    */
    static int postfixevaluation(String exp)
    {
         Stack s1=new Stack();
        for (int i=0;i<exp.length();i++)
        {
            char c=exp.charAt(i);
           if(Character.isDigit(c))
            {
                s1.push(c-'0');
            }
            else
            {
               int val1=s1.pop();
                int val2=s1.pop();
                switch(c)
                 {
                    case '+':
                    s1.push(val2+val1);
                    break;
                     
                    case '-':
                    s1.push(val2- val1);
                    break;
                     
                    case '/':
                    s1.push(val2/val1);
                    break;
                     
                    case '*':
                    s1.push(val2*val1);
                    break;
                    
                    default:
                    break;
              }
                
            }
        }
        
        return s1.pop();
    }
  
 
    public static void main(String args[])
    {
      //   String infix_exp="a+(b+c)+d*q";
     //   String postfix_exp=infixtopostfix(infix_exp);
     //   System.out.println("Postfix expression is "+postfix_exp+"\n");
        
        String postfix_exp="231*+9-";  
        int postfix_eval=postfixevaluation(postfix_exp);
        System.out.println("Evaluated postifix / Infix expression is "+postfix_eval+"\n");
        
    }
}
