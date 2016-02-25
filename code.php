<?
    //TEST
    name_variable = test42;

    test42 = "OK";
    #STACK
    ${name_variable}.put();
    #STACK

    #INFOS;

    #DBG_PROG;
?>
