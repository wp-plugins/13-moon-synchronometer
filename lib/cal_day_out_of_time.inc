<?php // cal_day_out_of_time.inc


// Provide a bit of an intro
if ($this_mysql_date_pieces[2] == 24) {$intro_txt = "Tomorrow is the ";} else {$intro_txt = "Yesterday was the ";}

echo "<div id=\"doot\" title=\"Day out of Time - July 25\">";

echo "<div style=\"float: left; text-align: left; margin-top: 13px; margin-left: 13px; max-width: 250px; \">\n";
echo "The Day Out of Time marks the end of one solar cycle and the next.";
echo "</div>";

echo "<div style=\"float: left; text-align: left; margin-top: 13px; margin-left: 13px; max-width: 250px; \">\n";
echo "The Day out of Time, which falls on July 25 each cycle, is the day before the new year.\n";
echo "</div>";

echo "<div style=\"float: left; text-align: left; margin-top: 13px; margin-left: 13px; max-width: 250px; \">\n";
echo "The new year begins with July 26th and ends with July 24, only 364 days.  The missing day is The Day Out of Time, giving the calendar 365 days.";
echo "</div>";

echo "<div style=\"float: left; text-align: left; margin-top: 13px; margin-left: 13px; max-width: 250px; \">\n";
echo "<P>This topic and others such as <a target=\"_BLANK\" class=tool href=\"http://en.wikipedia.org/wiki/Jos%C3%A9_Arg%C3%BCelles\">Day out Of Time</a> is explained here, and perhaps you'll understand why it is celebrated.\n";
echo "</div>\n";

echo "</div>\n";


?>