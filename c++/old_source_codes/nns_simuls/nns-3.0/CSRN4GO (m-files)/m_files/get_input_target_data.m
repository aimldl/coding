function [board,data]=get_input_target_data(board);

% get_input_target_data      Generate the input and target data sets
%
% Input data is a Go board status.
% Target data is the number of stones in the same group or string size.
%
% data
%   .input
%   .target
%   .estimate
%   .stats

board_max=board.cfg.size;
% Number of boards = number of input data sets.    
no_data_sets                = 7;
board.cfg.N_b               = no_data_sets;
% Empty boards for input and target data sets, respectively.
BOARD_STATUS_TMP            = zeros( board_max,board_max );    
STRING_SIZE_TMP             = zeros( board_max,board_max );
for jj=1:no_data_sets,
    % SS (String Size)
    data.target(jj).SS      = STRING_SIZE_TMP;
end;

% Retrieve the input and target data
% data_01 places stones manually.
data.cfg.is_read=0;
    if ( board_max==2 ),
    input_target_data_sample_2x2_01;
elseif ( board_max==3 ),
    input_target_data_sample_3x3_01;
end;
data.cfg.is_read=1;

for jj=1:no_data_sets,
    % ssf2nif converts string sizes on a board to its board status.
    % BS (Board Status)
    data.input(jj).BS       = ssf2nif( data.target(jj).SS );
    % Estimated string size will be calculated with NNs later.
    data.estimate(jj).SS    = zeros( board_max,board_max );
end;