#!/usr/bin/python
import os, filecmp, time

class bcolors: 
# Getting colours in terminal: http://goo.gl/xRxQPg
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
# (cygwin) make mintty as default shell : http://goo.gl/1RrGAr

def getFileNamesWithExtension( path , extension ):
    return [f for f in os.listdir(path) if f.endswith(extension)]

def timedcall(fn, *args):
    "Call function with args; return the time in seconds"
    t0 = time.time()
    result = fn(*args)
    t1 = time.time()
    return t1-t0

def test( inFileList ):
    t0 = time.time()
    for f in inFileList:
        dotIDX = f.find('.in')
        print  #adds a line
        print 13*' ', "in: %s" % f
        print '{0:.4f} sec:   {1} '.format(timedcall(os.system, './main %s' % f),\
            "out: " '%s' % (f[0:dotIDX]+'.out'))
        if filecmp.cmp('./%s' % f[0:dotIDX]+'.intest', './%s' % f[0:dotIDX]+'.out', shallow=False):
            # shallow = false compares the file contents else it compares file statistics
            testStr = bcolors.OKGREEN + "PASSED!" + bcolors.ENDC
        else:
            testStr = bcolors.FAIL + "FAILED!" + bcolors.ENDC
        print 13*' ', testStr
    print; print '%6.9f total.' % (time.time()-t0) #print out the total time taken

def main():
    inFiles = getFileNamesWithExtension(".", ".in")
    outFiles = getFileNamesWithExtension(".", ".out")
    assert len(inFiles) == len(outFiles), \
     " no_Of_'.in'_files=%d ! no_Of_'.out'_files=%d" % (len(inFiles), len(outFiles))
    test( inFiles )
    for f in getFileNamesWithExtension(".", ".intest"):
        os.remove("./" + f)

if __name__ == "__main__":
    main()