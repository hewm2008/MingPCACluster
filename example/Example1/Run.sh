#!/bin/sh
#$ -S /bin/sh
#Version1.0	hewm@genomics.org.cn	2022-07-03
echo Start Time : 
date

### run without pop.info
#../../bin/MingPCACluster	-InVCF	Khuman.vcf.gz	-OutPut	OUT	


### run with  pop.info
../../bin/MingPCACluster	-InVCF	Khuman.vcf.gz	-OutPut	OUT	-InSampleGroup	pop.info	

echo End Time : 
date
