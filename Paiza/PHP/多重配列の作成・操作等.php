<?php
    // 配列の宣言
    $nums = array();
    
    $n = trim(fgets(STDIN));
    
    // 配列読み込みと格納
    for($i = 0 ; $i < $n ; $i++)
    {
        // 入力から読み込んで半角スペースで分解
        $input = trim(fgets(STDIN));
        $input = explode(" ", $input);
        
        //　分解した配列を配列に格納して多重配列に。
        array_push($nums, $input);
    }
    
    //　多重配列の列挙
    foreach($nums as $key1 => $value1)
    {
        foreach($value1 as $key2 => $value2)
        {
            echo $value2." ";
        }
        echo "\n";
``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````    }

    // 多重配列の特定の値の操作
    $nums[0][2] = 100;
    echo $nums[0][2];
?>  ``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````