<?php
    solve();

    function solve()
    {
        $n = trim(fgets(STDIN));
        $n = explode(" ", $n);
        $max = $n[0];
        $person = $n[1];
        $table = array();
        for($i = 0 ; $i < $max ; $i++)
        {
            $table[] = 0;
        }
        
        for($i = 0 ; $i < $person ; $i++)
        {
            $a = trim(fgets(STDIN));
            $a = explode(" " , $a);
            $nop = $a[0];
            $place = $a[1];
            // 席に座れるか確認
            if(check($table, $nop, $place, $max))
            {
                // 席に座る
                for($j = 0 ; $j < $nop ; $j++)
                {
                    $table[$place-1] = 1;
                    $place++;
                    // 席の最大数を超えたら一つ目の椅子にする（環状処理）
                    if($place > $max) $place = 1;
                }
            }
        }
   
        echo array_sum($table);
    }
    
    //　すでに席に座られているか確認
    function check($table, $nop, $place, $max)
    {
        $n = 0;
        for($i = 0 ; $i < $nop ; $i++)
        {
            $n += $table[$place-1];
            $place++;
              // 席の最大数を超えたら一つ目の椅子にする（環状処理）
            if($place > $max)
            {
                $place = 1;
            }
        }
        if($n == 0) return true;
        else return false;
    }
?>