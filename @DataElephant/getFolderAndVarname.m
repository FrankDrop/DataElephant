function [filename,cumhash,varname,ori_id] = getFolderAndVarname(obj,hash,step)

    id_cum      = hash(:,(1:(end-obj.hashlength)));
    u_id_cum    = unique(id_cum,'rows');
    filename    = cell(size(u_id_cum,1),1);
    cumhash     = cell(size(u_id_cum,1),1);
    varname     = cell(size(u_id_cum,1),1);
    ori_id      = cell(size(u_id_cum,1),1);

    for ii=1:size(u_id_cum,1)
        ori_id{ii}      = find(all(id_cum == repmat(u_id_cum(ii,:),size(id_cum,1),1),2));
        varname{ii}     = cell(length(ori_id{ii}),1);
        cumhash{ii}     = u_id_cum(ii,:);

        for jj=1:length(ori_id{ii})
            varname{ii}{jj}     = ['H_' hexhash(obj,hash(ori_id{ii}(jj),((end-(obj.hashlength-1)):end)))];
        end
        
        if isempty(u_id_cum)
            filename{ii} = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/D.mat'];
        else
            filename{ii} = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/' hexhash(obj,u_id_cum(ii,(end-(obj.hashlength-1)):end)) '/D.mat'];
        end
    end
end