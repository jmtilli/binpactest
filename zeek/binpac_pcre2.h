#ifndef bro_pcre_h
#define bro_pcre_h
#include <stdio.h>
#include <assert.h>
#include <string>
using namespace std;
// TODO: use configure to figure out the location of pcre.h
#define PCRE2_CODE_UNIT_WIDTH 8
#include "pcre2.h"
namespace zeek {
class RE_Matcher {
public:
   RE_Matcher(const char* pat){
       pattern_ = "^";
       pattern_ += "(";
       pattern_ += pat;
       pattern_ += ")";
       pcre_   = NULL;
       Compile();
   }
   ~RE_Matcher() {
#if 0
       if (pcre_) {
           pcre_free(pcre_);
       }
#endif
   }
   int Compile() {
       //const char *err = NULL;
       int errcode;
       PCRE2_SIZE erroffset = 0;
       pcre_ = pcre2_compile(pattern_.c_str(), pattern_.length(),
                                    0,  // options,
                                    &errcode,
                                    &erroffset,
                                    NULL);
       if (pcre_ == NULL) {
           fprintf(stderr,
                   "Error in RE_Matcher::Compile(): %d:%d\n",
                   erroffset, errcode);
           return 0;
       }
       return 1;
   }

   int MatchPrefix (const char* s, int n){
       const char *err=NULL;
       assert(pcre_);
       const int MAX_NUM_OFFSETS = 30;
       int offsets[MAX_NUM_OFFSETS];
       pcre2_match_data *match_data;
       int off;

       match_data = pcre2_match_data_create_from_pattern(pcre_, NULL);

       int ret = pcre2_match(pcre_,
                                   //pextra_,  // pcre_extra
                                   //NULL,  // pcre_extra
                                   s, n,
                                   0,     // offset
                                   0,     // options
                                   match_data,
                                   NULL);
       if (ret < 0) {
           pcre2_match_data_free(match_data);
           return -1;
       }
       assert(pcre2_get_ovector_pointer(match_data)[0] == 0);
       off = pcre2_get_ovector_pointer(match_data)[1];
       pcre2_match_data_free(match_data);
       return off;
   }
protected:
   pcre2_code *pcre_;
   string pattern_;
};
};
#endif
