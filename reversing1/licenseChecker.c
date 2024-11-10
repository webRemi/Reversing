#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KEY_SIZE 10

char *modify_key(char *key);
void check_key(char *new_key);

int main(int argc, char *argv[]) {
  char key[KEY_SIZE+1];
  printf("> Enter the license key: ");
  if (fgets(key, sizeof(key), stdin) == NULL) {
    fprintf(stderr, "Error: Failed to read the key.\n");
    return EXIT_FAILURE;
  }

  size_t len = strlen(key);

  if (len > 0 && key[len - 1] == '\n') {
    key[len - 1] = '\0';
  }

  if (len != KEY_SIZE) {
    fprintf(stderr, "Error: The key must be exactly %d characters long.\n", KEY_SIZE);
    return EXIT_FAILURE;
  }

  printf("> You entered key: %s\n", key);

  char *new_key = modify_key(key);

  check_key(new_key);

  return EXIT_SUCCESS;
}

char *modify_key(char *key) {
  char temp = key[0];
  key[0] = key[KEY_SIZE-1];
  key[KEY_SIZE-1] = temp;
  return key;
}

void check_key(char *new_key) {
  if (strcmp(new_key, "correctkey") == 0)
    puts("> Correct");
  else
    puts("> Incorrect");
}
