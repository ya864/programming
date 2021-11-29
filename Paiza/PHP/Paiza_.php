<?php
    solve();
    function solve()
    {
        $a = trim(fgets(STDIN));
        $b = trim(fgets(STDIN));
        if($a == $b)
        {
            echo "OK";
        }
        else
        {
            echo "NG";
        }
    }
?>