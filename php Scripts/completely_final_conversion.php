<?php
include 'excel_reader.php';     // include the class

// creates an object instance of the class, and read the excel file data
$excel = new PhpExcelReader;
$excel -> read('web_designing.xls');

// Excel file data is stored in $sheets property, an Array of worksheets
/*
The data is stored in 'cells' and the meta-data is stored in an array called 'cellsInfo'

Example (firt_sheet - index 0, second_sheet - index 1, ...):

$sheets[0]  -->  'cells'  -->  row --> column --> Interpreted value
         -->  'cellsInfo' --> row --> column --> 'type' (Can be 'date', 'number', or 'unknown')
                                            --> 'raw' (The raw data that Excel stores for that data cell)
*/





$maxNum = 1000;  //define the max number of allowed entries in a table



 
$person_entries = 0 ;  //-->no of present entries in a table
$no_of_fields = 0;     // no of fields in the table
$content_of_fields = array();   //strig titles of the table


//this step is not needed but implemented for clarity
$table_data = array( array( array() ) ); // 2d array to store the content of each cell as string.... the last array is  for string index ;


$sheet = $excel->sheets[0] ; //defined the variable to the first sheet

  //This section is to leave the top margin
  $flag = 0;
  
  $x = 1 ;
  
   while ( $x <= $sheet['numRows'] ) {
   
    $y = 1;
   
    while( $y <= $sheet['numCols']) {

      if( isset($sheet['cells'][$x][$y]) )
     {

     	$content_of_fields[ $no_of_fields++ ] = $sheet['cells'][$x][$y];  //We found the first column with column headings

      $flag = 1;
     }
   
      $y++;
    }  
  
    $x++;

 if( $flag == 1 )
   	break;
 
  }


$index_of_entries = 0; // index start from the very first entry 

  while( $x <= $sheet['numRows'] ) {
    $y = 1;
    

    $column_left_dist = 0; // if usable/data columns starts at k(say) cells later, then we define this beginning of our row  (This section is use to leave the the left margin)
    
    while( $y <= $sheet['numCols']) {

      if( isset( $sheet['cells'][$x][$y] ) )
      {
       $cell = $sheet['cells'][$x][$y];   // We have each cell info in $cell

       $table_data[ $index_of_entries ][ $column_left_dist ] = $cell ;  //assigning to table

   //   echo "info= ".$cell.'<br/>';

$column_left_dist++ ;

      }

      $y++ ;
    
    } 

     $index_of_entries++ ; 
  
    $x++ ;
  }


$person_entries = $index_of_entries;  //Sieze the number of entries int the table


$sheet_name = $excel ->boundsheets[0]['name'];       // this is name of sheet



//echo "person entries=". $table_data[2][2]. '<br/>';

$table_id = array();  // Identifier or name of the table 

for( $i = 0 ; $i < $person_entries ; $i++ ){

$table_id[$i] = $sheet_name. ( $i + 1 );

}

$json_data = array();

for( $i = 0 ; $i < $person_entries ; $i++ ){

for( $j = 0 ; $j < $no_of_fields ; $j++ )
{

$json_data [ $person_id[$i] ] [ $content_of_fields[$j] ] = $table_data[$i][$j];
}

}
echo $json_data = json_encode( $json_data );

?>
