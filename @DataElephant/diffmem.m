function dmem = diffmem(obj)
    ii          = memory;
    mem_cur     = ii.MemUsedMATLAB;
    dmem        = (mem_cur-obj.memuse)/1024;
    fprintf('Memory added = %1.3f Kb.\n',dmem);
    obj.memuse  = mem_cur;
end