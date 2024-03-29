# Owltech Middleware

This repo contains all the necessary low-levelish software to communicate the STM32 HAL and application code for FreeRTOS, controlling Robomaster and some Gobilda hardware. 

## NOTES:

If you were to change the C/C++ standard used, remember to change it in the `IntelliSense`, `makefile`, and `c_cpp_propperties.json`

For more [formatting options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html) see the link.

## Running for compile

Currently, we're using `make` as our compilation tool. 

By default, make will build whats specified at first, this is the defacto target.

    make

If you wish to compile any other target, then do:

    make targetName

The syntax is like:

```
targetName: dependency1
    compiler -flags [args...]
```

*Note:* Targets may also be defined as dependencies, thus calling a compilation chain

**FYI:** Make can also execute bash commands, so that's why you'll sometimes see commands being used in the `Makefile`. 

In fact the syntax, for declaring, using, and even storing [variables](https://www.gnu.org/savannah-checkouts/gnu/make/manual/make.html#Reading) is the same!


## Resources

If you would like to learn more about the used tools and information, then check:

* [Quick intro to Makefiles](https://www.youtube.com/watch?v=aw9wHbFTnAQ) (Video)
* [GNU Make manual](https://www.gnu.org/savannah-checkouts/gnu/make/manual/make.html#Reading)
* The GNU Make [Book](https://learning.oreilly.com/library/view/the-gnu-make/9781457189883/). John Graham-Cumming. No Starch Press
 