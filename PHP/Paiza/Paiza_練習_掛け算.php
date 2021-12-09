
/*
    Paiza練習　掛け算
*/

<?php
    solve();
    function solve()
    {
        $a = trim(fgets(STDIN));
        $b = trim(fgets(STDIN));
        
        echo $a*$b;
    }
?>