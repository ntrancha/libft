<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_date.php                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 15:43:35 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/08 15:43:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function test_date($h, $i, $s, $m, $d, $y)
{
    $timestamp = mktime($h, $i, $s, $m, $d, $y);
    $commandes = './a.out '.$y.' '.$d.' '.$m.' '.$h.' '.$i.' '.$s;
    $prog = exec($commandes);
    if ($prog != $timestamp)
    {
        echo $prog." ".$timestamp." : ";
        return 0;
    }
    echo $prog."           :";
    return 1;
}

$y = 1970;
while ($y < 1995)
{
    $m = 1;
    while ($m < 13)
    {
        $d = 1;
        while ($d < 27)
        {
            test_date(11, 2, 50, $m, $d++, $y);
                echo "$y $m $d\n";
            //else
              //  echo mktime(11, 2, 50, $m, $d, $y)."\n";
        }
        $m++;
    }
    $y++;
}
?>

