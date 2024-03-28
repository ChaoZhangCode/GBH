echo off
echo Watch me delete Data directories
#rm -r "./Data/BVPoutLIN/BVPout_iterations"
#rm -r "./Data/BVPoutLIN/BVPout_sols"
#rm -r "./Data/BVPoutLIN/BVPout_sys"
#mkdir "./Data/BVPoutLIN/BVPout_iterations"
#mkdir "./Data/BVPoutLIN/BVPout_sols"
#mkdir "./Data/BVPoutLIN/BVPout_sys"
#rm -r "./Data/BVPoutEXP/BVPout_iterations"
#rm -r "./Data/BVPoutEXP/BVPout_sols"
#rm -r "./Data/BVPoutEXP/BVPout_sys"
#mkdir "./Data/BVPoutEXP/BVPout_iterations"
#mkdir "./Data/BVPoutEXP/BVPout_sols"
#mkdir "./Data/BVPoutEXP/BVPout_sys"
#
#rm -r "./Data/BVPoutKERR/BVPout_iterations"
#rm -r "./Data/BVPoutKERR/BVPout_sols"
#rm -r "./Data/BVPoutKERR/BVPout_sys"
#mkdir "./Data/BVPoutKERR/BVPout_iterations"
#mkdir "./Data/BVPoutKERR/BVPout_sols"
#mkdir "./Data/BVPoutKERR/BVPout_sys"
echo Successfully deleted Data directories.
#
#                  p  n(x)  m                               rH    alpha   beta    chi    ICalpha  ICbeta  deltachi  plotvar
./Execs/BVPDM.exe  8  61   31  16  -6  1.0    10.0      10.0    0.9         0.0     10.0         0.1         1
#
echo BVP Executed.
