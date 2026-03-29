#define SJKJSON_IMPLEMENTATION
#include "sjkjson.h"

JSON_Element* test_make_json() {
  RootStack roots = {0};

  JSON_Element* root = push_array(&roots, "");
    root = push_object(&roots, "");

      append_to_json(root, make_json_string("name", "France"));
      append_to_json(root, make_json_string("capital", "Paris"));
      append_to_json(root, make_json_num("population", 67364357));
      append_to_json(root,  make_json_num("area", 551695));
      append_to_json(root, make_json_string("currency", "Euro"));

        root = push_array(&roots, "languages"); 
          append_to_json(root, make_json_string("", "French")); 
        root = pull_root(&roots);
      
      append_to_json(root, make_json_string("region", "Europe"));
      append_to_json(root, make_json_string("subregion", "Western Europe"));
      append_to_json(root, make_json_string("subregion", "https://upload.wikimedia.org/wikipedia/commons/c/c3/Flag_of_France.svg"));

    root = pull_root(&roots);
   root = pull_root(&roots);
  return root;
}

int main(void) {
  //const char* src_file_path = "./products.json";
  
  //JSON_Element* json = parse_json_file(src_file_path); 
  
  JSON_Element* json = test_make_json();
  
  String_Builder sb = {0}; 
  dump_json(&sb, json, 0);

  write_sb_to_file("./test.json", sb);

  return 0;
}
