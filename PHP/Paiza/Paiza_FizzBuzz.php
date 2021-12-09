<?php
    solve();
    function solve()
    {
        $n = trim(fgets(STDIN));
        for($i = 1 ; $i <= $n ; $i++)
        {
            if($i % 3 == 0 && $i % 5 == 0)
            {
                echo "Fizz Buzz";
            }
            else if ($i % 3 == 0)
            {
                echo "Fizz";
            }
            else if ($i % 5 == 0)
            {
                echo "Buzz";
            }
            else
            {
                echo $i;
            }
            echo "\n";
        }
    }
?>