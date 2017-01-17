function alphas = fuzzy_pertinencia(h1t, h2t, vec_h1, vec_h2)

% /////////////////////////////////////
% Triang. Membership to H1
% /////////////////////////////////////
u1 = zeros(1,length(vec_h1));

if(h1t <= vec_h1(1))
    u1(1) = 1;

elseif (h1t >= vec_h1(length(vec_h1)))
    u1(length(vec_h1)) = 1;
    
else
    for i = 1:(length(vec_h1)-1)
        if((h1t >= vec_h1(i)) && (h1t < vec_h1(i+1)))
            left = (i>2)*(i - 1) + 1;
            u1(i) = trimf(h1t, [vec_h1(left) vec_h1(i) vec_h1(i+1)]);
            u1(i+1) = 1 - u1(i);
        end
    end 
end

% /////////////////////////////////////
% Triang. Membership to H2
% /////////////////////////////////////
u2 = zeros(1,length(vec_h2));

if(h2t <= vec_h2(1))
    u2(1) = 1;

elseif (h2t >= vec_h2(length(vec_h2)))
    u2(length(vec_h2)) = 1;
    
else
    for i = 1:(length(vec_h2)-1)
        if((h2t >= vec_h2(i)) && (h2t < vec_h2(i+1)))
            left = (i>2)*(i - 1) + 1;
            u2(i) = trimf(h2t, [vec_h2(left) vec_h2(i) vec_h2(i+1)]);
            u2(i+1) = 1 - u2(i);
        end
    end 
end
% Alphas
alphas = (u1') * u2;