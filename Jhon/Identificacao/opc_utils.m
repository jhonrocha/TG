clear
sInfo = opcserverinfo('localhost')
da = opcda('localhost','RSLinx OPC Server')
connect(da)
nsFull = getnamespace(da)
nsPart = getnamespace(da,'Depth',1)
nsPart(1).Nodes = getnamespace(da, 'StartItemID', nsPart.FullyQualifiedID, 'Depth',1)
nsPart(1).Nodes = getnamespace(da, 'StartItemID', nsPart.FullyQualifiedID, 'Depth',1)
for index = 1: size(nsPart.Nodes)
    nsPart.Nodes(index)
end