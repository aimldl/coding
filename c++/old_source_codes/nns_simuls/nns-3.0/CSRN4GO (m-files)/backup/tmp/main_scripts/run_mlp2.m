% run_mlp               Run simulations for MLP
%
% Written by Tae-Hyung D. Kim, tk424@mst.edu
% This project is started on Apr. 8, 2008 (Tue).
% Version: 1.0
% Last updated: May. 13, 2008 (Tue)
%
% Convention for variable names
%   scalar      all small letters, e.g. is_over
%   vector      the first letter is capitalized, e.g. Input
%   matrix      all large letters, csrn.srn(x,y).scope.POSITION
%   structure   all small letters

% Clear all the previous records and figures
clear all; close all; clc;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Choose a cell type for CNNS      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% User configurable options
% Option for Neural Networks Cells
opt_nnc=1;                               % 1: MLP, 2: SRN, 3: SRNwHR
opt_is_test=0;
brd_size=2;
if ( opt_is_test ==1 ),
    % Maximum number of iteration
    mm_max=5;                            % Averaging out "M"ean
    nn_max=10;                           % PSO, epochs "n"
    oo_max=20;                           % SRN, "O"uter loop
    ii_max=10;                            % SRN with hidden layer recurrence, "I"nner loop
else,
    mm_max=500;                           % Averaging out "M"ean
    nn_max=1000;                          % PSO, epochs "n"
    oo_max=20;                            % SRN, "O"uter loop
    ii_max=10;                            % SRN with hidden layer recurrence, next index for p
end;
is_disp=1;
disp_freq=100;
plot_y_scaler=10;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Call main.m to run simulations   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd ..
main2
