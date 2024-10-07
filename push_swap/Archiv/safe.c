struct s_list stack_b;
    int len_a;
    int i;
    int piece[0];
    int piece[1];
    int div;
    struct s_list cur;
    
    len_a = ft_lstsize(stack_a);
    if(len_a == 1)
        return (0);

    stack_b = (stack_a)malloc(len_a * sizeof(stack_a));
    if(!stack_b)
    {
        stack_b = NULL;
        free(stack_b);
        return(NULL);
    }
    
    int pieces[len_a / 2];
    i = 0;
    piece[0] = 1;
    piece[1] = 1;
    cur = stack_a;
    div = 2;
    int j = 1;
    while(len_a / div > 2 && j <= div)
    {
        while(i < (len_a / div * j))
        {
            piece[j - 1] =  piece[j - 1] * cur->data;
            cur = cur->next;
            i++;
        }
        j++;
    }
    i = 0;
    if(div == 2 && piece[1] > piece[0])
    {
        while(i < (len_a / div))
        {
            ft_rotate(stack_a);
            i++; 
        }
    }
    }
}