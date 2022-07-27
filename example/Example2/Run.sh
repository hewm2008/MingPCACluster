#!/bin/sh
#$ -S /bin/sh
#Version1.0	hewm@genomics.org.cn	2022-07-04
echo Start Time : 
date
## beta  so 慢  不建议用
../../bin/MingPCACluster	-InSTOgem	Test.gem.gz	-OutPut	Test	-CellBin	50	
echo End Time : 
date
