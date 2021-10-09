#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../libs/Encoder.h"

static ERROR Verify(char* message);

static ERROR Verify(char* message)
{
  if(message==NULL)
  {
    return FALSE;
  }
  else return TRUE; //
}

Message newMessage(char* message)
{
  Message myMessage = NULL;
  myMessage = malloc(sizeof(Message));
  myMessage->code = calloc(BUFSIZ, sizeof (char));
  if(Verify(message))
  {
    strncpy(myMessage->code, message, BUFSIZ);
    myMessage->length = strnlen(message, BUFSIZ);
  }
  else
  {
    myMessage->length = 0;
  }
  return myMessage;
}

ERROR setMessage(Message frame, char* string)
{
  if(string==NULL)
  {
    return FALSE;
  }
  else
  {
    strncpy(frame->code, string, BUFSIZ);
    return TRUE;
  }
}

char* getMessage(Message frame)
{
  if(Verify(frame->code))
  {
    return frame->code;
  }
  else return NULL;
}

ERROR encodeMessage(Message frame, size_t offset)
{
  if(!frame)
  {
    return FALSE;
  }
  if(!frame->code)
  {
    return FALSE;
  }
  for(int x=0; x<frame->length; x++)
  {
    frame->code[x] += offset;
  }
  return TRUE;
}

ERROR Ascii(int code[], size_t offset, size_t size)
{
  if(size==0)
  {
    return FALSE;
  }
  for(size_t x=0; x<size; x++)
  {
    code[x] += offset;
    printf("%c", code[x]);
  }
  return TRUE;
}
