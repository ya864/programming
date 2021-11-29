<?php
    solve();
    function solve()
    {
        $a = array();
        for($i = 0 ; $i < 5 ; $i++)
        {
            $a[] = trim(fgets(STDIN));
        }
        
        // 最小値を返すmin関数
        $ans = min($a);
        echo $ans;
    }
?>