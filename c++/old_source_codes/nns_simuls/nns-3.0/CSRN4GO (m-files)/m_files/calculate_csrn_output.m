function [csrn,data,e_t]=calculate_csrn_output(csrn,data,e_t,bb,board_max,oo_max);

% calculate_csrn_output      Calculate cellular SRN output
%
% Note the difference between Recurrent Networks (RN) and Simultaneous RN (SRN).
% In practice, RN becomes SRN if RN iterates several times.
% At my best knowledge, there exist no contemporary programming language
% that can "simultaneously" feed back the output to the input.

for x=1:board_max,
    for y=1:board_max,
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        U           = csrn.cell.loc(x,y).U;
        N_n         = csrn.cell.loc(x,y).N_n;
        
        W_u         = csrn.cell.id(N_n-1).W_u;
        W_v         = csrn.cell.id(N_n-1).W_v';

        for oo=1:oo_max,
            H           = tansig( W_u*U );
            V           = floor( W_v*H );
            U(1,:)      = V;                % Recurrence
        %    disp( sprintf('oo=%d\t[%d,%d,%d,%d]',oo,V(1),V(2),V(3),V(4)));
        end;
%        Y_hat       = reshape( V,board_max, board_max );
        Y_hat(x,y)  = V;
        e_t(1,N_n-1)= e_t(1,N_n-1)+abs( data.target(bb).SS(x,y)-V );
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end;
end;
csrn.cell.Y_hat=Y_hat;
data.estimate(bb).SS=Y_hat;

