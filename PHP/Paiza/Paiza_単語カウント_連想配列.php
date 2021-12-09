<?php
    solve();
    function solve()
    {
        $n = trim(fgets(STDIN));
        $n = explode(" ", $n);
        $array = array();
        
        // 要素の出てきた回数のカウント
        for($i = 0 ; $i < count($n) ; $i++)
        {
            // 配列に値が存在するなら数を増やす
            if(array_key_exists($n[$i],$array))
            {
                $array[$n[$i]]++;
            }
            // 配列に値が存在しないなら新たに追加する
            else
            {
                $array =  $array + array($n[$i] => 1);
            } 
        }    
        
        // 連想配列の要素をforeachで列挙
        foreach($array as $key => $value)
        {
            echo $key." ".$value."\n";
        }
    }
?>