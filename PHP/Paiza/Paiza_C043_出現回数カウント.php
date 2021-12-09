<?php
    $n = trim(fgets(STDIN));
    $nums = trim(fgets(STDIN));
    $nums = explode(" ", $nums);
    $cntArr = array();
    
    for($i = 0 ; $i < $n ; $i++)
    {
        if(array_key_exists($nums[$i], $cntArr))
        {
            $cntArr[$nums[$i]]++;
        }
        else
        {
            $cntArr = $cntArr + array($nums[$i] => 1);
        }
    }
    // 連想配列の値の降順でソート
    arsort($cntArr);

    // 連想配列をキーと値に分解。そのままだと要素毎に処理する方法が分からなかった。
    $keys = array_keys($cntArr);
    $values = array_values($cntArr);
    
    // 一番多い数字を格納する配列。
    $ansArr = array();
    $ansArr[] = $keys[0];
    
    for($i = 1 ; $i < count($keys) ; $i++)
    {
        if($values[$i] != $values[$i-1])
        {
            break;
        }
        else
        {
            $ansArr[] = $keys[$i];
        }
    }
    sort($ansArr);
    
    $ans = implode(" ", $ansArr);
    echo $ans;
    
?>
