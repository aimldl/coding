function pso=config_pso2(board,nns,iter_max,nnc_type),
% config_pso              Configure PSO (Particle Swarm Intelligence)
%
% Velocity update equation 
% The velocity update equation (1) is comprised of:
%    inertia of the previous velocity, 
%    the cognitive acceleration term, and 
%    the social acceleration term. 
% This velocity is moving towards both to the local best of the given particle and the global best positions of the whole population. 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         pso.cfg.p(article)        %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% There is only one particle for 2x2 using symmetry.
[row_W_u,clmn_W_u] = size( nns.cell.W_u );
[row_W_v,clmn_W_v] = size( nns.cell.W_v );

if ( nnc_type=='mlp' )
    pso.cfg.p.d=row_W_u.*clmn_W_u+row_W_v.*clmn_W_v;   % dimension
elseif ( nnc_type=='srn' ),
    pso.cfg.p.d=row_W_u.*clmn_W_u+row_W_v.*clmn_W_v;   % dimension
elseif ( nnc_type=='snr' ),
    [row_W_h,clmn_W_h] = size( nns.cell.W_h );
    pso.cfg.a.d=row_W_h.*clmn_W_h;      % dimension
    pso.cfg.p.d=row_W_u.*clmn_W_u+row_W_v.*clmn_W_v +pso.cfg.a.d;   % dimension
else,
    error( sprintf('Unknown Neural Netws Cell type: %s',nnc_type) );
end;

pso.cfg.p.size=20;                   % Number of particles        
pso.cfg.p.w=0.8;
pso.cfg.p.c1=2;
pso.cfg.p.c2=2;
pso.cfg.p.l_id_max=2.0;
pso.cfg.p.v_id_max=100;
pso.cfg.p.target_fitness=0;           % Number of acceptable errors
pso.cfg.p.iter_max=iter_max; % time_n_max determines the maximum number of iteration

if ( nnc_type=='snr' ),
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %      pso.cfg.p.a(ssociate)        %
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %    pso.a.iter_max  = nns.cfg.hl_iter_max;
    pso.cfg.a.iter_max=nns.cfg.hl_iter_max; % Maximum number of hidden layer iteration (inner loop)
    pso.cfg.a.size=10;                 % Number of associates per particle
    pso.cfg.a.w=0.2;
    pso.cfg.a.c1=1;
    pso.cfg.a.c2=1;
    pso.cfg.a.target_fitness=pso.cfg.p.target_fitness;
    pso.cfg.a.l_id_max=pso.cfg.p.l_id_max;
    pso.cfg.a.v_id_max=pso.cfg.p.v_id_max;
    
    % Substitute values in variables, just to reduce the number of input arguments to function init_pso
    pso.cfg.N_h=nns.cfg.N_h;
    pso.cfg.N_s=board.cfg.N_s;
end;