
<!-- form for decoding gregorian to 13 moon -->

<td>
<div class="styled-select black rounded">
<select name="dcode_day">
<option value="1"<?php if ($dcode_day == "1") echo " SELECTED";?>>01 &nbsp;</option>
<option value="2"<?php if ($dcode_day == "2") echo " SELECTED";?>>02</option>
<option value="3"<?php if ($dcode_day == "3") echo " SELECTED";?>>03</option>
<option value="4"<?php if ($dcode_day == "4") echo " SELECTED";?>>04</option>
<option value="5"<?php if ($dcode_day == "5") echo " SELECTED";?>>05</option>
<option value="6"<?php if ($dcode_day == "6") echo " SELECTED";?>>06</option>
<option value="7"<?php if ($dcode_day == "7") echo " SELECTED";?>>07</option>
<option value="8"<?php if ($dcode_day == "8") echo " SELECTED";?>>08</option>
<option value="9"<?php if ($dcode_day == "9") echo " SELECTED";?>>09</option>
<option value="10"<?php if ($dcode_day == "10") echo " SELECTED";?>>10</option>
<option value="11"<?php if ($dcode_day == "11") echo " SELECTED";?>>11</option>
<option value="12"<?php if ($dcode_day == "12") echo " SELECTED";?>>12</option>
<option value="13"<?php if ($dcode_day == "13") echo " SELECTED";?>>13</option>
<option value="14"<?php if ($dcode_day == "14") echo " SELECTED";?>>14</option>
<option value="15"<?php if ($dcode_day == "15") echo " SELECTED";?>>15</option>
<option value="16"<?php if ($dcode_day == "16") echo " SELECTED";?>>16</option>
<option value="17"<?php if ($dcode_day == "17") echo " SELECTED";?>>17</option>
<option value="18"<?php if ($dcode_day == "18") echo " SELECTED";?>>18</option>
<option value="19"<?php if ($dcode_day == "19") echo " SELECTED";?>>19</option>
<option value="20"<?php if ($dcode_day == "20") echo " SELECTED";?>>20</option>
<option value="21"<?php if ($dcode_day == "21") echo " SELECTED";?>>21</option>
<option value="22"<?php if ($dcode_day == "22") echo " SELECTED";?>>22</option>
<option value="23"<?php if ($dcode_day == "23") echo " SELECTED";?>>23</option>
<option value="24"<?php if ($dcode_day == "24") echo " SELECTED";?>>24</option>
<option value="25"<?php if ($dcode_day == "25") echo " SELECTED";?>>25</option>
<option value="26"<?php if ($dcode_day == "26") echo " SELECTED";?>>26</option>
<option value="27"<?php if ($dcode_day == "27") echo " SELECTED";?>>27</option>
<option value="28"<?php if ($dcode_day == "28") echo " SELECTED";?>>28</option>
<option value="29"<?php if ($dcode_day == "29") echo " SELECTED";?>>29</option>
<option value="30"<?php if ($dcode_day == "30") echo " SELECTED";?>>30</option>
<option value="31"<?php if ($dcode_day == "31") echo " SELECTED";?>>31</option>
</select>
</div>
</td>

<td>
<select name="dcode_mo">
<option value="1"<?php if ($dcode_mo == "1") echo " SELECTED";?>>1</option>
<option value="2"<?php if ($dcode_mo == "2") echo " SELECTED";?>>2</option>
<option value="3"<?php if ($dcode_mo == "3") echo " SELECTED";?>>3</option>
<option value="4"<?php if ($dcode_mo == "4") echo " SELECTED";?>>4</option>
<option value="5"<?php if ($dcode_mo == "5") echo " SELECTED";?>>5</option>
<option value="6"<?php if ($dcode_mo == "6") echo " SELECTED";?>>6</option>
<option value="7"<?php if ($dcode_mo == "7") echo " SELECTED";?>>7</option>
<option value="8"<?php if ($dcode_mo == "8") echo " SELECTED";?>>8</option>
<option value="9"<?php if ($dcode_mo == "9") echo " SELECTED";?>>9</option>
<option value="10"<?php if ($dcode_mo == "10") echo " SELECTED";?>>10</option>
<option value="11"<?php if ($dcode_mo == "11") echo " SELECTED";?>>11</option>
<option value="12"<?php if ($dcode_mo == "12") echo " SELECTED";?>>12</option>
</select>
</td>

<td><input type=text size=5 maxlength=4 name=dcode_yr value="<?php echo "$dcode_yr";?>"></td>
<td><input type=submit value="SYNC" class="sync_button" title="CLICK to reload with new date"></td>

