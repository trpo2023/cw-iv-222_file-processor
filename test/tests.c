#include <ctest.h>
#include <stdlib.h>

#include <fileprocessor.h>

extern int bufferIndex;
extern char buffer[200][MAX_FILELENGTH];

CTEST(isFile, testFile1)
{
    int result = isFile("test/testDir/notFile");
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(isFile, testFile2)
{
    int result = isFile("test/testDir/file");
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(scanDirMy, scanDir1)
{
    scandirMy("test/tmpTests/test0/");
    int result = bufferIndex;
    int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(scanDirMy, scanDir2)
{
    scandirMy("test/tmpTests/test1/");
    int result = bufferIndex;
    int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(getCode, getcodeEXT)
{
    char* str = "<Ext>";
    int result = getCode(&str);
    int expected = CODE_EXT;
    ASSERT_EQUAL(expected, result);
}

CTEST(getCode, getcodeName)
{
    char* str = "<Name>";
    int result = getCode(&str);
    int expected = CODE_NAME;
    ASSERT_EQUAL(expected, result);
}

CTEST(getCode, getcodeInc)
{
    char* str = "<Inc>";
    int result = getCode(&str);
    int expected = CODE_INC;
    ASSERT_EQUAL(expected, result);
}

CTEST(getCode, getcodeTxt)
{
    char* str = "54gf<Inc>";
    int result = getCode(&str);
    int expected = CODE_TEXT;
    ASSERT_EQUAL(expected, result);
}
