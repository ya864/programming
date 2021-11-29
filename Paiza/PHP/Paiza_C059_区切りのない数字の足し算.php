<?php
    $n = trim(fgets(STDIN));
    
    // 答えを計算するための配列
    $nums = array();
    // 今回は４桁なので４回０を挿入する
    for($i = 0 ; $i < 4 ; $i++)
    {
        $nums[] = 0;
    }
    
    /*
        PHPは、例えば0101という入力を変数に格納したあと，
        C#の文字列と同じようにarray[0]のようにして、
        特定の桁の数字を取り出すことができた。
        そのまま特に変換することなく足し算を行うことも可能だった。
    */
    for($i = 0 ; $i < $n ; $i++)
    {
         $input = trim(fgets(STDIN));
         for($j = 0 ; $j < 4 ; $j++)
         {
             $nums[$j] += $input[$j];
         }
    }
    
    for($i = 0 ; $i < 4 ; $i++)
    {
        echo $nums[$i]%2;
    }
?>
