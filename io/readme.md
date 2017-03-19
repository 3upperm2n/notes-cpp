### iostream  rules
* can not assign on stream to another
* can not init stream parameters
* can not copy stream

```c++
ofstream out1, out2;
out1 = out2;
```

### manage state
```c++
auto old_state = cin.rdstate(); // current cin state
cin.clear();					// clear the error flags 
process_input(cin);				// use cin
cin.setstate(old_state); 		// restore the oldstate

```
