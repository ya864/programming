/*
    スペースで区切られた英単語列が与えられます。
    英単語列に含まれる英単語の出現回数を出現した順番に出力してください。

    Paizaの練習問題のCランク
    同じ要素の数を数える問題。
    PHP は連想配列が普通の配列と同じように使えるが、
    この問題では連想配列として使えなかった。
    よく調べないといけないが、
    array_count_valuesを使用して、別の連想配列に出現回数を記録することができた。
*/

<?php
    solve();
    function solve(){
        $input = trim(fgets(STDIN));
        $input = explode(" ",$input);
        
        $name = array();
        $nums = array();
        for($i = 0 ; $i < count($input) ; $i++)
        {
            $s = $input[$i];
            if(!in_array("$s",$name))
            {
                $name[] = "$s";
            }
        }
        $nums = array_count_values($input);
        
        for($i = 0 ; $i < count($name) ; $i++)
        {
            echo $name[$i] . " " . $nums[$name[$i]] . "\n";
        }
    }
?>
