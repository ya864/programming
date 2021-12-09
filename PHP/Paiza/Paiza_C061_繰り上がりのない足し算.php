<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    
    $n1 = strval($input[0]); 
    $n2 = strval($input[1]);
    // $n1と$n2の桁数が違うと桁毎に計算できないので揃える
    // このままだと2桁と1桁の時に答えが３桁表示になってしまう。
    if(strlen($n1) != strlen($n2))
    {
        $n1 = sprintf("%03d", $n1);
        $n2 = sprintf("%03d", $n2);
    }
    
    $ans = array();
    for($i = 0 ; $i < strlen($n1) ; $i++)
    {
        $a = $n1[$i]+$n2[$i];
        if($a >= 10) $a -= 10;
        $ans[] = $a;
    }
    
    foreach($ans as $b)
    {
        echo $b;
    }
    
?>
