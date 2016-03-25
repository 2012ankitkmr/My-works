<?php



// Sample data to convert variable to json
$item_type=1;
$string_key='ankit';
$string_value='NIT';
$string_extra='Jalandhar';
$is_public=true;
$public_contacts=false;

$post_data=array(
	             'item'=>array('item_type_id' => $item_type,
	                          'string_key' => $string_key,
	                          'string_value' => $string_value,
	                          'string_extra' => $string_extra,
	                          'is_public' => $is_public,
	                         'is_public_for_contact' => $public_contacts)
                 );
echo $post_data=json_encode($post_data);
?>