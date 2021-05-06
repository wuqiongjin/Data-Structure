bool isValid(char * s)
{
    if(s == NULL)
        return true;
    Stack st;
    StackInit(&st);
    while(*s)
    {
        if(*s == '(' || *s =='[' || *s == '{')
        {
            StackPush(&st,*s);
        }
        else
        {
            //先判断是否为空很重要！！！！！！！！
            //如果上来就给] ，此时栈为空，那么也返回false
            if(StackEmpty(&st))
            {
 //!!!!!!!!!!!!这里要注意不要 `````内存泄漏``````！！！！！！!!!!
                StackDestory(&st);
                return false;
            }

            if(*s == ')')
            {
                if(StackTop(&st) != '(')
                {
                    StackDestory(&st);
                    return false;
                }
                StackPop(&st);
            }
            else if (*s == ']')
            {
                if(StackTop(&st) != '[')
                {
                    StackDestory(&st);
                    return false;
                }
                StackPop(&st);
            }
            else if(*s == '}')
            {
                if(StackTop(&st) != '{')
                {
                    StackDestory(&st);
                    return false;
                }
                StackPop(&st);
            }
        }
        ++s;
    }

        //最后需要判断栈是否为空，栈不为空，代表不匹配，返回false
        bool ret = StackEmpty(&st);
        StackDestory(&st);
        return ret;
}