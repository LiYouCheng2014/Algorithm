    char infixExpression[100] = {};
    char suffixExpression[100] = {};
    
    getInfixExpression(infixExpression);
    printf("中缀%s\n",infixExpression);
    
    InfixExpressionToSuffixExpression(infixExpression, suffixExpression);
    printf("后缀%s真的\n",suffixExpression);
    
    calculateSuffixExpression(suffixExpression);



InitStack(*S)
DestoryStack(*S)
ClearStack(*S)
StackEmpty(S)
GetTop(S,*e)
Push(*S,e)
Pop(*s,*e)
StackLength(S)
