#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

struct StringPeace {
StringPeace() {
s = 0;
len = 0;
}
StringPeace(char* from) {
this->s = from;
this->len = strlen(from);
}
StringPeace(char* from, char* to) {
this->s = from;
this->len = to - from;
}
bool operator== (const StringPeace& other) const {
if (len != other.len)
return false;
return strncmp(s, other.s, len) == 0;
}
bool operator!= (const StringPeace& other) const {
if (len != other.len)
return true;
return strncmp(s, other.s, len) != 0;
}
const char operator[] (int index) const {
return s[index];
}
int size() const {
return len;
}
const string as_string() const {
return string(s, s + len);
}
char* s;
int len;
};
vector<StringPeace> toks;
static vector<StringPeace> tokenize(char* s)
{
toks.clear();
for (int i = 0; s[i]; i++)
{
switch (s[i])
{
case ' ':
case '\n':
case '\t':
break;
case '(':
case ')':
toks.push_back(StringPeace(s + i, s + i + 1));
break;
default:
int j = i;
while (s[j] != 0 && s[j] != ' ' && s[j] != '\n' && s[j] != ')' && s[j] != '(')
j++;
toks.push_back(StringPeace(s + i, s + j));
i = j - 1;
break;
}
}
return toks;
}

char f[2000];
char ids[3000];
char* readNextLine(char* s) {
gets(s);
//assert(s[0] != 0);
return s;
}

struct Node {
enum Type {
ID,
OR,
AND,
OPTIONAL,
EXACTLY_DIGITS,
EXACTLY_LETTERS,
UPTO_DIGITS,
UPTO_LETTERS,
TO,
TIMES,
};
Type type;
string id;
int N;
Node* first;
Node* next;
};

inline void xassert(bool b) {
if (!b) {
int i = 5;
printf("%d", 7 / (i - i));
}
}
template<class T>
struct Pool {
T* elements;
T* top;
Pool() {
elements = new T[20000];
}
void reset() {
top = elements;
}
T* getNext() {
xassert (top - elements < 20000 - 2);
return top++;
}
int size() {
return top - elements;
}
};
Pool<Node> nodes;
Node* createNode() {
Node* top = nodes.getNext();
top->N = 0;
top->id = "";
top->first = top->next = 0;
return top;
}

int GetLongest(Node* node) {
if (node->type == Node::ID)
return node->id.size();
if (node->type == Node::TO)
return 1;
if (node->type == Node::OPTIONAL) {
return GetLongest(node->first);
}
if (node->type == Node::EXACTLY_DIGITS || node->type == Node::EXACTLY_LETTERS ||
node->type == Node::UPTO_DIGITS || node->type == Node::UPTO_LETTERS) {
return node->N;
}
if (node->type == Node::TIMES) {
int r = GetLongest(node->first);
if (r > 10000)
return 10000;
return r * node->N;
}
if (node->type == Node::AND) {
int res = 0;
for (Node* c = node->first; c; c = c->next) {
res += GetLongest(c);
}
return res;
}
if (node->type == Node::OR) {
int res = 0;
for (Node* c = node->first; c; c = c->next) {
int res2 = GetLongest(c);
res = max(res, res2);
}
return res;
}

assert (false);
return 0;
}
bool isValidID(const string& id) {
if (id.empty())
return false;
for (int i = 0; i < id.size(); i++) {
if (id[i] >= 'A' && id[i] <= 'Z' ||
id[i] >= '0' && id[i] <= '9' ||
id[i] == '-')continue;
return false;
}
return true;
}
bool isValidForRange(char c) {
if (c >= 'A' && c <= 'Z' ||
c >= '0' && c <= '9')
return true;
return false;
}
bool isValid(Node* node) {
if (!node) {
return false;
}
if (node->type == Node::OR || node->type == Node::AND) {
if (node->first == 0)
return false;
}
if (node->type == Node::ID) {
return isValidID(node->id);
}
if (node->type == Node::TO) {
if (node->id[0] > node->id[1])
return false;
if (isdigit(node->id[0]) != isdigit(node->id[1]))
return false;
return isValidForRange(node->id[0]) && isValidForRange(node->id[1]);
}
if (node->type == Node::EXACTLY_DIGITS || node->type == Node::EXACTLY_LETTERS ||
node->type == Node::UPTO_DIGITS || node->type == Node::UPTO_LETTERS ||
node->type == Node::TIMES) {
if (node->N < 2 || node->N > 12)
return false;
}
for (Node* c = node->first; c; c = c->next) {
if (!isValid(c)) {
return false;
}
}

return true;
}

int getN(const StringPeace& s) {
if (s.size() > 2)
return 0;
int a = atoi(s.as_string().c_str());
if (a < 2 || a > 12)
return 0;
return a;
}

StringPeace OPEN_BRACKET("(");
StringPeace CLOSE_BRACKET(")");
StringPeace TO_KEYWORD("to");
StringPeace LETTER_KEYWORD("letter");
StringPeace DIGIT_KEYWORD("digit");
StringPeace EXACTLY_KEYWORD("exactly");
StringPeace UPTO_KEYWORD("upto");
StringPeace DIGITS_KEYWORD("digits");
StringPeace LETTERS_KEYWORD("letters");
StringPeace OPTIONAL_KEYWORD("optional");
StringPeace TIMES_KEYWORD("times");
StringPeace OR_KEYWORD("or");

Node* getNextBlock(int& pos);
Node* getNext(int& pos) {
if (toks[pos] == OPEN_BRACKET) {
pos++;
Node* result = getNextBlock( pos);
if (pos >= toks.size() || toks[pos] != CLOSE_BRACKET)
return 0;
pos++;
return result;
}
Node* node = createNode();
if (pos + 1 < toks.size() && toks[pos + 1] == TO_KEYWORD) {
node->type = Node::TO;
if (toks[pos].size() != 1) return 0;
if (toks[pos + 2].size() != 1) return 0;
node->id = string(1, toks[pos][0]) + toks[pos + 2][0];
pos += 3;
return node;
} else if (toks[pos] == LETTER_KEYWORD) {
node->type = Node::TO;
node->id = "AZ";
pos++;
return node;
} else if (toks[pos] == DIGIT_KEYWORD) {
node->type = Node::TO;
node->id = "09";
pos++;
return node;
} else if (toks[pos] == EXACTLY_KEYWORD) {
if (toks[pos + 2] == LETTERS_KEYWORD) {
node->type = Node::EXACTLY_LETTERS;
node->N = getN(toks[pos + 1]);
} else if (toks[pos + 2] == DIGITS_KEYWORD) {
node->type = Node::EXACTLY_DIGITS;
node->N = getN(toks[pos + 1]);
} else {
return 0;
}
pos += 3;
return node;
} else if (toks[pos] == UPTO_KEYWORD) {
if (toks[pos + 2] == LETTERS_KEYWORD) {
node->type = Node::UPTO_LETTERS;
node->N = getN(toks[pos + 1]);
} else if (toks[pos + 2] == DIGITS_KEYWORD) {
node->type = Node::UPTO_DIGITS;
node->N = getN(toks[pos + 1]);
} else {
return 0;
}
pos += 3;
return node;
} else {
node->type = Node::ID;
node->id = toks[pos].as_string();
pos++;
}

return node;
}


Node* getNextMod(int& pos) {
Node* c = getNext(pos);
if (c == NULL)
return NULL;
while (true) {
if (pos < toks.size() && toks[pos] == OPTIONAL_KEYWORD) {
Node* p = createNode();
p->type = Node::OPTIONAL;
p->first = c;
c = p;
pos++;
} else if (pos + 1 < toks.size() && toks[pos + 1] == TIMES_KEYWORD) {
Node* p = createNode();
p->type = Node::TIMES;
p->first = c;
p->N = getN(toks[pos]);
c = p;
pos += 2;
} else {
break;
}
}
if (pos < toks.size() && toks[pos] == OR_KEYWORD) {
pos++;
Node* x = getNextMod( pos);
Node* p = createNode();
p->type = Node::OR;
p->first = c;
c->next = x;
c = p;
}
return c;
}
Node* getNextBlock(int& pos) {
if (pos >= toks.size()) {
return NULL;
}
Node* node = createNode();
node->type = Node::AND;
Node* last = NULL;
while (true) {
if (pos >= toks.size())
break;

if (toks[pos] == ")") {
break;
}
Node* c = getNextMod(pos);
if (c == NULL)
return NULL;
if (last == NULL) node->first = c; else last->next = c;
last = c;
}
return node;

}
Node* buildTree(int& pos) {
if (pos >= toks.size())
return 0;
Node* result = getNextBlock(pos);
if (pos != toks.size())
return 0;
return result;
}

#define SPLIT '*'
#define MATCH '&'

struct State {
char from;
char to;
State* out;
State* out1;
int condId;
};
struct Fragment {
State* start;
list<State**> outs;
};

Pool<Fragment> fragments;
Pool<State> states;

State* newState() {
State* s = states.getNext();
s->out = s->out1 = 0;
s->condId = 0;

return s;
}

Fragment* newFragment() {
Fragment* s = fragments.getNext();
s->outs.clear();
s->start = 0;
return s;
}

Fragment* createStates(Node* node) {
if (node->type == Node::ID) {
Fragment* f = newFragment();
State* last = 0;
for (int i = 0; i < node->id.size(); i++) {
State* s = newState();
s->from = s->to = node->id[i];
if (last == 0)
f->start = s;
else
last->out = s;
last = s;
}
f->outs.push_back(&last->out);
return f;
} else if (node->type == Node::TO) {
Fragment* f = newFragment();
State* s = newState();
s->from = node->id[0];
s->to = node->id[1];
f->start = s;
f->outs.push_back(&s->out);
return f;
} else if (node->type == Node::EXACTLY_DIGITS || node->type == Node::EXACTLY_LETTERS) {
Fragment* f = newFragment();
State* last = 0;
for (int i = 0; i < node->N; i++) {
State* s = newState();
s->from = node->type == Node::EXACTLY_DIGITS ? '0' : 'A';
s->to = node->type == Node::EXACTLY_DIGITS ? '9' : 'Z';
if (last == 0)
f->start = s;
else
last->out = s;
last = s;
}
f->outs.push_back(&last->out);
return f;
} else if (node->type == Node::OPTIONAL) {
Fragment* e = createStates(node->first);
State* s = newState();
s->from = SPLIT;
s->out = e->start;

e->start = s;
e->outs.push_back(&s->out1);
return e;
} else if (node->type == Node::UPTO_DIGITS || node->type == Node::UPTO_LETTERS) {
Fragment* f = newFragment();
State* last = 0;
for (int i = 0; i < node->N; i++) {
State* split = newState();
split->from = SPLIT;
State* s = newState();
s->from = node->type == Node::UPTO_DIGITS ? '0' : 'A';
s->to = node->type == Node::UPTO_DIGITS ? '9' : 'Z';
split->out = s;
if (last == 0)
f->start = split;
else {
last->out->out = split;
last->out1 = split;
}
last = split;
}
f->outs.push_back(&last->out->out);
f->outs.push_back(&last->out1);
return f;
} else if (node->type == Node::TIMES) {
Fragment* f = 0;
for (int i = 0; i < node->N; i++) {
Fragment* e = createStates(node->first);
if (f == 0) {
f = e;
} else {
for (list<State**>::iterator o = f->outs.begin(); o != f->outs.end(); o++) {
**o = e->start;
}
e->start = f->start;
f = e;
}
}
return f;
} else if (node->type == Node::AND) {
Fragment* f = 0;
for (Node* cur = node->first; cur; cur = cur->next) {
Fragment* e = createStates(cur);
if (f == 0) {
f = e;
} else {
for (list<State**>::iterator o = f->outs.begin(); o != f->outs.end(); o++) {
**o = e->start;
}
e->start = f->start;
f = e;
}
}
return f;
} else if (node->type == Node::OR) {
Fragment* f = 0;
for (Node* cur = node->first; cur; cur = cur->next) {
Fragment* e = createStates(cur);
if (f == 0) {
f = e;
} else {
State* s = newState();
s->from = SPLIT;
s->out = f->start;
s->out1 = e->start;
f->start = s;
f->outs.splice(f->outs.end(), e->outs);
}
}
return f;
} else {
assert(false);
}

return 0;
}

struct StateList {
State* st[50000];
int size;
void push_back(State* s) {
st[size++] = s;
}
void clear() {
size = 0;
}
};

int condId;

void addState(StateList& conds, State* st) {
if (st == 0 || st->condId == condId)
return;
st->condId = condId;
if (st->from == SPLIT) {
addState(conds, st->out);
addState(conds, st->out1);
} else {
conds.push_back(st);
}
}
StateList tmpList[2];

bool canMatch(char* s, State* st) {
StateList* conds = &tmpList[0];
StateList* newconds = &tmpList[1];
conds->clear();
condId++;
addState(*conds, st);
//assert(states.size() < 10000);

for (int i = 0; s[i]; i++) {
condId++;
newconds->clear();
for (int cc = 0; cc < conds->size; cc++) {
State* c = conds->st[cc];
if (c->from <= s[i] && s[i] <= c->to) {
addState(*newconds, c->out);
}
}
//assert (newconds->size < 10000);
swap(conds, newconds);
}
for (int cc = 0; cc < conds->size; cc++) {
if (conds->st[cc]->from == MATCH) {
return true;
}
}
return false;
}

int main(int argc, char* argv[]) {
#ifdef LAPTOP
freopen("test.in", "r", stdin);
freopen("test.out", "w", stdout);
#endif

char ts[100];
int T = atoi(readNextLine(ts));

while (T--) {
readNextLine(f);
tokenize(f);
int pos = 0;
nodes.reset();
fragments.reset();
states.reset();

Node* root = buildTree(pos);
bool valid = isValid(root);

if (!valid) {
printf("Format does not conform\n");
} else if (GetLongest(root) > 2000) {
printf("Matches too long ID\n");
valid = false;
}

State* st = 0;
if (valid) {
Fragment* f = createStates(root);
State* match = newState();
match->from = match->to = MATCH;
for (list<State**>:: iterator o = f->outs.begin(); o != f->outs.end(); o++) {
**o = match;
}
st = f->start;
}

int Q = atoi(readNextLine(ts));

while (Q--) {
readNextLine(ids);
if (valid) {
bool b = canMatch(ids, st);
printf("%s\n", b? "Valid-ID" : "Invalid-ID");
}
}
printf("\n");
}


return 0;
}
