#!/bin/bash
# the tail of the result should look like this:
# 
#
# 
#    -s    to display computer specific structure information
#    -t    to execute simulation 
#    -h    to display more complete help
#
# 

./magee -cpu -f one two -? -est three four | more

